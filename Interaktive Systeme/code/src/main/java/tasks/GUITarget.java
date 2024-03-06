package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.util.Random;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

/**
 * Mouse Target: Objekt, das mit der Maus anzuklicken ist
 *
 * @author Eckhard Kruse
 */
class GUITarget {

    private Group guiTargetNode;    // JavaFx Objekt im Szenengraph

    GUITarget(int no) {
        guiTargetNode = new Group();
        Rectangle r=new Rectangle(0, 0, 80, 50);
        r.setStroke(Color.WHITE);
        r.setFill(Color.BURLYWOOD);
        guiTargetNode.getChildren().add(r);
        Text t=new Text(10, 30, "Nr. "+no);
        t.setFont(new Font(25.));
        t.setFill(Color.WHITE);
        guiTargetNode.getChildren().add(t);
    }

    Node getGuiObject() {
        return guiTargetNode;
    }

    /*
     * Initialisierung mit zufälliger Position innerhalb der Fenstermaße
     *
     * @param width Breite des Fensters
     * @param height Höhe des Fensters
     */
    void reset(double width, double height) {
        Random rnd = new Random();

        guiTargetNode.setTranslateX(rnd.nextDouble()*(width-120)+20);
        guiTargetNode.setTranslateY(rnd.nextDouble()*(height-70)+10);
        guiTargetNode.setEffect(new ColorAdjust());
    }
}

