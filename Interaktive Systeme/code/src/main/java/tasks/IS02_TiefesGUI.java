package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.util.Duration;

/*
 * Aufgabe IS-02: Objekte mit Tiefenstaffelung
 *
 * @author Eckhard Kruse
 */
public class IS02_TiefesGUI extends Application {

    private UIElementList elements;

    double oldMouseX, oldMouseY;
    double actMouseX, actMouseY;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {

        Group root = new Group();
        Canvas canvas = new Canvas(600, 500);
        root.getChildren().add(canvas);
        Scene scene = new Scene(root);

        elements = new UIElementList();

        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Handlers to resize window
        scene.widthProperty().addListener(evt -> draw(gc));
        scene.heightProperty().addListener(evt -> draw(gc));

        canvas.widthProperty().bind(scene.widthProperty());
        canvas.heightProperty().bind(scene.heightProperty());

        scene.addEventHandler(MouseEvent.MOUSE_PRESSED, evt -> mousePressed(evt));
        scene.addEventHandler(MouseEvent.MOUSE_DRAGGED, evt -> mouseMoved(evt));
        scene.addEventHandler(MouseEvent.MOUSE_MOVED, evt -> mouseMoved(evt));
        scene.addEventHandler(MouseEvent.MOUSE_RELEASED, evt -> mouseReleased(evt));

        draw(gc);

        Timeline timeline = new Timeline(new KeyFrame(
        Duration.millis(50), evt -> timerEvent(gc)));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();

        stage.setTitle("Interaktive Systeme - IS02 - Tiefes GUI");
        stage.setScene(scene);
        stage.show();
    }

    /**
     * redraws the entire screen: Background + elements
     *
     * @param gc GraphicsContext
     */
    private void draw(GraphicsContext gc) {

        gc.setFill(UIElement.colorBackground);
        gc.fillRect(0, 0, gc.getCanvas().getWidth(), gc.getCanvas().getHeight());
        elements.render(gc);
    }

    /**
     * mouse event handler
     *
     * @param evt event
     */
    private void mousePressed(MouseEvent evt) {
        actMouseX=evt.getX();
        actMouseY=evt.getY();
        elements.mouseMoved(evt.getX(), evt.getY(),2, 0, 0);
    }

    /**
     * mouse event handler
     *
     * @param evt event
     */
    private void mouseReleased(MouseEvent evt) {
        elements.mouseMoved(evt.getX(), evt.getY(),3, 0, 0);
    }

    /**
     * mouse event handler
     *
     * @param evt event
     */
    private void mouseMoved(MouseEvent evt) {
        oldMouseX=actMouseX;
        oldMouseY=actMouseY;
        actMouseX=evt.getX();
        actMouseY=evt.getY();
        elements.mouseMoved(evt.getX(), evt.getY(),1, actMouseX-oldMouseX, actMouseY-oldMouseY);
    }

    /**
     * timer event handler, updates and renders elements
     *
     * @param gc GraphicsContext is required for rendering
     */
    public void timerEvent(GraphicsContext gc) {
        // TODO: do elements.update(), with relative mouse motion since last update
        // TODO: use oldMouseX/Y
        draw(gc);
    }
}
