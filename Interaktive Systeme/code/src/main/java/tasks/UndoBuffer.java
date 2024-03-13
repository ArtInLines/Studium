package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.lang.Math;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.shape.Rectangle;

/**
 * Undo-Buffer, Undo- und Redo-Funktionen
 *
 * @author Eckhard Kruse
 */
class UndoBuffer {

    final int maxUndo=16;
    private final Group[] buffer;    // Undo Buffer
    public int start;
    public int act_end;
    public int total_end;


    UndoBuffer() {
        buffer=new Group[maxUndo];
        start = act_end = total_end = 0;
    }

    /*
     * Erzeuge Clone vom Group-Objekt durch Deep Copy aller Kind-Objekte + Merkmale
     *
     * @param in zu kopierendes Group-Objekt
     * @return Kopie vom Group-Objekt
     */
    Group clone(Group in) {
        Group c=new Group();
        if(in!=null)
            for(Node n: in.getChildren()) {
                Rectangle r=(Rectangle)n;
                Rectangle cr=new Rectangle(r.getWidth(), r.getHeight());
                cr.setFill(r.getFill());
                cr.setStroke(r.getStroke());
                cr.setTranslateX(r.getTranslateX());
                cr.setTranslateY(r.getTranslateY());
                c.getChildren().add(cr);
            }
        return c;
    }

    void print() {
        System.out.print(start);
        System.out.print(", ");
        System.out.print(act_end);
        System.out.print(", ");
        System.out.println(total_end);
    }

    /*
     * Speichere Aktion/Zustand in Form der gesamten Node-Group
     *
     * @param g Group, die aktuellen Zustand repräsentiert
     */
    void storeAction(Group g) {
    	buffer[act_end] = clone(g);
        act_end = (act_end + 1)%maxUndo;
        total_end = act_end;
        if (total_end == start) start = (start + 1)%maxUndo;
        print();
    }

    /*
     * Undo-Aktion durchführen
     *
     * @return Group, welche den gespeicherten Zustand repräsentiert
     */
    Group undo() {
        Group g = new Group();
        if (act_end != start) {
            act_end = act_end <= 0 ? (maxUndo - act_end - 1) : ((act_end - 1)%maxUndo);
            g = buffer[act_end];
        }
        print();
        return g;
    }

    /*
     * Redo-Aktion durchführen
     *
     * @return Group, welche den herzustellenden Zustand repräsentiert
     */
    Group redo() {
        Group g = new Group();
        if (act_end != total_end) {
            g = buffer[act_end];
            act_end = (act_end + 1)%maxUndo;
        }
        print();
    	return g;
    }
}
