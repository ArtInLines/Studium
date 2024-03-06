package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.awt.AWTException;
import java.awt.Robot;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.geometry.Point2D;
import javafx.scene.Group;
import javafx.scene.ImageCursor;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.image.WritableImage;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Shape;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;


/*
 * Aufgabe IS-07: Mouse-Tuning
 *
 * @author Eckhard Kruse
 */
public class IS07_MouseTuning extends Application {

    Robot mouseRobot; // Für volle Mauskontrolle...
    Group cursor;
    Shape cursorShape;
    Text display;

    // Mouse zeiger
    double actX, actY, oldX, oldY, difX, difY, avgDifX, avgDifY;  // Daten zur Mausposition: Aktuell, alt, relative zur vorigen
    double rotation; // Mausrichtungen

    // Mouse ziele + Statistik
    final int targetCnt = 5; // Anzahl der Targets
    int currentTarget;

    final int msStep = 20;
    int msTime;
    double totalDistance;
    double minDistance;
    boolean startTimer;

    GUITarget[] targets;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {

        Group root = new Group();

        Scene scene = new Scene(root, 1000, 700);
        scene.setFill(new Color(0.2, 0.3, 0.5, 1.0));

        // Create GUI Targets
        targets=new GUITarget[targetCnt];
        for(int i=0; i<targetCnt; i++) {
            targets[i]=new GUITarget(i+1);
            targets[i].reset(scene.getWidth(), scene.getHeight());
            root.getChildren().add(targets[i].getGuiObject());
        }
        initTargets(scene);

        // Textanzeige
        display = new Text(20, 20, "");
        display.setFont(new Font(15));
        display.setFill(Color.WHITE);
        root.getChildren().add(display);

        // Mauszeiger vorbereiten
        cursorShape = new Polygon(0, 0, -15, 15, -10, 5, -30, 7, -30, -7, -10, -5, -15, -15);
        cursorShape.setFill(Color.WHITE);
        cursorShape.setStroke(Color.BLACK);
        cursor = new Group();
        cursor.getChildren().add(cursorShape);
        root.getChildren().add(cursor);

        actX=500; actY=250; // Startposition
        difX=0; difY=0;
        avgDifX=0; avgDifY=0;  // geglättete Bewegung -> Rotation

        // Handlers to resize window
        scene.addEventHandler(MouseEvent.MOUSE_MOVED, evt -> mouseMoved(evt));
        scene.addEventHandler(MouseEvent.MOUSE_PRESSED, evt -> mouseClicked(evt, scene));

        WritableImage i=new WritableImage(1,1);
        i.getPixelWriter().setColor(0, 0, new Color(0.2,0.3,0.5,0.01));
        scene.setCursor(new ImageCursor(i));

        stage.setTitle("Interaktive Systeme - IS07 - Mouse Tuning");
        stage.setScene(scene);
        stage.show();

        Timeline timeline = new Timeline(new KeyFrame(
                Duration.millis(msStep), evt -> displayUpdate(scene)));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();

        // Robot für volle Mousezeiger-Kontrolle
        try {
            mouseRobot=new Robot();  // alter awt Robot
        } catch (AWTException e) {
	}
    }

    /*
     * Anzuklickende Mausziele initialisieren
     *
     * @param scene JavaFX Scene
     */
    private void initTargets(Scene scene) {

        minDistance=0;
        for (int i=0; i<targetCnt; i++) {
            targets[i].reset(scene.getWidth(), scene.getHeight());
            if(i>0) {
                double x=targets[i].getGuiObject().getTranslateX()-
                            targets[i-1].getGuiObject().getTranslateX();
                double y=targets[i].getGuiObject().getTranslateY()-
                            targets[i-1].getGuiObject().getTranslateY();
                minDistance+=Math.sqrt(x*x+y*y);
            }
        }
        msTime = 0;
        totalDistance = 0;
        currentTarget = 0;
        startTimer = false;
    }

    /*
     * Mouseevent-Handler: Bewegung abfangen und Position für eigene Darstellung berechnen
     *
     * @param evt MouseEvent
     */
    private void mouseMoved(MouseEvent evt) {
        difX=evt.getX()-300;
        difY=evt.getY()-200;
        avgDifX=0.8*avgDifX + 0.2*difX;
        avgDifY=0.8*avgDifY + 0.2*difY;

        // TODO: improve rotation and translation of cursor
        // based on raw input as relative motion (difX, difY)
        rotation=180*Math.atan2(avgDifY, avgDifX)/Math.PI;
        actX-=difX/2;
        actY+=difY/3;

        if(startTimer)
            totalDistance+=Math.sqrt(difX*difX+difY*difY);

        // Original Cursor-Position zurücksetzen für weitere relative Bewegungen
        mouseRobot.mouseMove((int)(300+evt.getScreenX()-evt.getX()), (int)(200+evt.getScreenY()-evt.getY()));
    }

    /*
     * Mouseevent-Handler: Click - Target getroffen?
     *
     * @param evt MouseEvent
     * @param scene Szene, die bei rechter Mousetaste neu initialisiert wird
     */
    private void mouseClicked(MouseEvent evt, Scene scene) {
        // target clicked?
        if(evt.getButton()==MouseButton.PRIMARY && currentTarget<targetCnt) {
            Node o=targets[currentTarget].getGuiObject();
            if(o.contains(o.sceneToLocal(actX, actY))) {
                currentTarget++;
                if(currentTarget==1)
                    startTimer=true;
                if(currentTarget>=targetCnt)
                    startTimer=false;
                o.setEffect(new ColorAdjust(0, -0.6, -0.4, 0));
            }
        }
        else if(evt.getButton()==MouseButton.SECONDARY) {
            // Rechtsklick: Targets neu setzen
            initTargets(scene);
        }
    }

    // nicht verwendet: private void mouseExited(MouseEvent evt)


    /*
     * Eigenen Mousecursor neu zeichnen
     *
     * @param scene Szene
     */
    private void displayUpdate(Scene scene) {
        // Check boundaries
    	if(actX<0) actX=0;
    	if(actX>=scene.getWidth()) actX=scene.getWidth()-1;
    	if(actY<0) actY=0;
    	if(actY>=scene.getHeight()) actY=scene.getHeight()-1;

        // Cursordarstellung aktualisieren
    	cursorShape.setRotate(rotation);

        // TODO: Adapt size of cursor based on ...
        double size=5;
        cursorShape.setScaleX(0.3*avgDifX + size/3);
        cursorShape.setScaleY(0.3*avgDifY + size);


        Point2D p=cursorShape.localToParent(0,0);
        cursor.setTranslateX(actX-p.getX());
        cursor.setTranslateY(actY-p.getY());

        // Timer ausgabe
        display.setText("Zeit: "+msTime+" ms   "+"Mausweg: "+((int)totalDistance)+" Pixel   "+
                "Direkter Weg: "+(int)minDistance+
                "    Speed: "+(int)(totalDistance*1000/(msTime+0.01))+" pixel/s");

        if(startTimer)
            msTime+=msStep;
    }
}
