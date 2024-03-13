package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.util.Random;
import javafx.application.Application;
import javafx.geometry.Point2D;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.effect.Glow;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

/*
 * Aufgabe IS-08: Editierbare Objekte mit Undo/Redo-Funktion
 *
 * @author Eckhard Kruse
 */
public class IS08_Undo extends Application {

    Group actState;   /// Aktueller Zustand=Objektbaum des UIs
    Node selectedObject;
    Point2D selectRel;

    UndoBuffer undo;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {

        Group root = new Group();
        Scene scene = new Scene(root, new Color(0.2, 0.3, 0.5, 1.0));

        actState = new Group();
        root.getChildren().add(actState);

        undo=new UndoBuffer();

        scene.addEventHandler(MouseEvent.MOUSE_PRESSED, evt -> mousePressed(evt));
        scene.addEventHandler(MouseEvent.MOUSE_DRAGGED, evt -> mouseDragged(evt));
        scene.addEventHandler(MouseEvent.MOUSE_RELEASED, evt -> mouseReleased(evt));
        scene.addEventHandler(KeyEvent.KEY_PRESSED, evt -> keyPressed(evt, root));

        stage.setTitle("Interaktive Systeme - IS08 - Undo");
        stage.setScene(scene);
        stage.show();
    }

    /*
     * Mouse-Event handler: Pressed
     *
     * @param evt Mouse-Event
     */
    private void mousePressed(MouseEvent evt) {
        if(evt.getButton()==MouseButton.PRIMARY) {   // Linksklick
            for(Node n: actState.getChildren()) {    // Vorbereiten für drag
                selectRel=n.parentToLocal(evt.getX(),evt.getY());
                if(n.contains(selectRel)) {
                    selectedObject=n;
                    n.setEffect(new Glow(1.0));
                    return;
                }
            }
        }
        else if(evt.getButton()==MouseButton.SECONDARY) {   // Rechtsklick
            for(Node n: actState.getChildren()) {   // Vorhandenes Element angeklickt -> löschen
                if(n.contains(n.parentToLocal(evt.getX(),evt.getY()))) {
                    actState.getChildren().remove(n);
                    undo.storeAction(actState);
                    return;
                }
            }
            // sonst Neues anlegen
            //Random rnd=new Random();
            Rectangle r=new Rectangle(200,100, new Color(0.4, 0.6*(new Random()).nextFloat(), 0.9, 1.0));
            r.setStroke(Color.WHITE);
            r.setTranslateX(evt.getX());
            r.setTranslateY(evt.getY());
            actState.getChildren().add(r);
            undo.storeAction(actState);
        }
    }

    /*
     * Mouse-Event handler: Objekt draggen
     *
     * @param evt Mouse-Event
     */
    private void mouseDragged(MouseEvent evt) {
        if(selectedObject!=null) {
            selectedObject.setTranslateX(evt.getX()-selectRel.getX());
            selectedObject.setTranslateY(evt.getY()-selectRel.getY());
        }
    }

    /*
     * Mouse-Event handler: Release
     *
     * @param evt Mouse-Event
     */
    private void mouseReleased(MouseEvent evt) {
        if(selectedObject!=null) {
            selectedObject.setEffect(new Glow(0));
            selectedObject=null;
            undo.storeAction(actState);
        }
    }

    /*
     * Key-Event Handler, um Undo- und Redo-Hotkeys abzufangen
     *
     * @param evt Mouse-Event
     */
    private void keyPressed(KeyEvent evt, Group root) {
        if(evt.getCode()==KeyCode.Z && evt.isControlDown()) {
            System.out.println("Undo");
            root.getChildren().remove(actState);
            actState = undo.undo();
            root.getChildren().add(actState);
    	}
        else if(evt.getCode()==KeyCode.Y && evt.isControlDown()) {
            System.out.println("Redo");
            root.getChildren().remove(actState);
            actState = undo.redo();
            root.getChildren().add(actState);
    	}
    }
}
