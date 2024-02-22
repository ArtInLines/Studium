package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */
import java.util.Random;
import javafx.geometry.Bounds;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.effect.Glow;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

/**
 * Single UI Element, renders itself based on coordinates and other data
 *
 * @author Eckhard Kruse
 */
class PhysicalElement {

    private double vx, vy, vrot;  // speed
    private Group sceneObject;    // JavaFx Object in scene;
    private boolean clicked;

    PhysicalElement() {
        sceneObject = new Group();
        Random rnd=new Random();
        // Initialize graphic representation with Random data
        double w=rnd.nextDouble()*200+100;
        double h=rnd.nextDouble()*100+100;
        Rectangle r=new Rectangle(-w/2,-h/2,w,h);
        r.setStroke(Color.WHITE);
        r.setFill(new Color(0.2+rnd.nextDouble()*0.7, 0.2+rnd.nextDouble()*0.7, 1.0, 1.0));
        sceneObject.getChildren().add(r);
        Text t=new Text("Object");
        t.setFont(new Font(30.));
        t.setFill(Color.WHITE);
        t.setTranslateX(-w*0.4);
        t.setTranslateY(-h*0.3);
        sceneObject.getChildren().add(t);
        clicked=false;
        sceneObject.addEventHandler(MouseEvent.MOUSE_ENTERED, evt -> mouseEntered(evt));
        sceneObject.addEventHandler(MouseEvent.MOUSE_EXITED, evt -> mouseExited(evt));
        sceneObject.addEventHandler(MouseEvent.MOUSE_PRESSED, evt -> mousePressed(evt));
        sceneObject.addEventHandler(MouseEvent.MOUSE_DRAGGED, evt -> mouseDragged(evt));
        sceneObject.addEventHandler(MouseEvent.MOUSE_RELEASED, evt -> mouseReleased(evt));
    }

    Node getSceneObject() {
        return sceneObject;
    }

    /**
     * Initialize element with random position
     *
     * @param width  screen width
     * @param height screen height
     */
    void setRandomPosition(double width, double height) {
        Random rnd = new Random();

        sceneObject.setTranslateX(rnd.nextDouble()*width);
        sceneObject.setTranslateY(rnd.nextDouble()*height);
        sceneObject.setRotate(rnd.nextDouble()*360);

        vx   = (rnd.nextDouble() - 0.5)*15;
        vy   = (rnd.nextDouble() - 0.5)*15;
        vrot = (rnd.nextDouble() - 0.5)*20;
    }

    /**
     * Update Element, calculate motion according to physical properties and laws
     * TODO: Objekt soll sich (wenn losgelassen) gemäß physikalischer Gesetze bewegen
     *
     * @param width  screen width
     * @param height screen height
     */
    void update(double width, double height) {  // Dimension bounds
        // TODO: Bewegung nur, wenn nicht mit Mauszeiger gezogen.

        // TODO: Trägheit

        // TODO: Fensterrand überprüfen ggf. abprallen
        Bounds b=sceneObject.boundsInParentProperty().getValue();
        // TODO: if(b.getMinX()<0 ) { ... }
        // etc.


        // Wind

        // Gleitreibung / Haftreibung

        // optional: Elastizität -> Federmodell...
    }

    /**
     * Event handler: When mouse hovers over object, highlight the object
     *
     * @param evt Mouse event
     */
    private void mouseEntered(MouseEvent evt) {
        sceneObject.setEffect(new Glow(0.5));
    }

    private double oldX, oldY;

    /**
     * Event handler: Mouse button is pressed
     *
     * @param evt Mouse event
     */
    private void mousePressed(MouseEvent evt) {
        sceneObject.setEffect(new Glow(1.0));
        clicked=true;
        oldX=evt.getSceneX();
        oldY=evt.getSceneY();
    }

    /**
     * Event handler: Mouse is dragged and pulls element with it
     * (-> calculate position and rotation)
     *
     * @param evt Mouse event
     */
    private void mouseDragged(MouseEvent evt) {
        // Vektor von Schwerpunkt zu Berührungspunkt
        double x=sceneObject.getTranslateX(); // Object-Koordinaten
        double y=sceneObject.getTranslateY();
        double xx=evt.getSceneX();   // Mouse-Koordinaten
        double yy=evt.getSceneY();

        double r1x = x - xx;
        double r1y = y - yy;
        double dist = Math.sqrt(r1x * r1x + r1y * r1y); // Distanz von Schwerpunkt

        // in Radians
        if (dist > 0.)
            vrot = ((xx-oldX) * r1y - (yy-oldY) * r1x) / dist / dist;
        else vrot = 0.f;

        double x2 = xx + (xx-oldX) + r1x * Math.cos(vrot) - r1y * Math.sin(vrot);
        double y2 = yy + (yy-oldY) + r1x * Math.sin(vrot) + r1y * Math.cos(vrot);
        vrot=Math.toDegrees(vrot);
        vx = x2 - x;
        vy = y2 - y;
        sceneObject.setTranslateX(x2);
        sceneObject.setTranslateY(y2);
        sceneObject.setRotate(sceneObject.getRotate()+vrot);

        oldX=xx;
        oldY=yy;
    }

    /**
     * Event handler: Mouse button is released, element can move freely
     *
     * @param evt Mouse event
     */
    private void mouseReleased(MouseEvent evt) {
        sceneObject.setEffect(new Glow(0.5));
        clicked=false;
    }

    /**
     * Event handler: Mouse is no longer hovering above element
     *
     * @param evt Mouse event
     */
    private void mouseExited(MouseEvent evt) {
        sceneObject.setEffect(new Glow(0));
    }

}
