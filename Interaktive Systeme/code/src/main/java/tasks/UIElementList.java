package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.util.Arrays;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.effect.BoxBlur;

/**
 * Array of UI Elements,
 * Iterates through elements and calls functions from individual elements
 *
 * @author Eckhard Kruse
 */
class UIElementList {
    UIElement elements[];

    /**
     * Constructs a list of elements with some random data
     *
     */
    UIElementList() {
        elements = new UIElement[100];
        for (int i = 0; i < elements.length; i++) {
            elements[i] = new UIElement();
            elements[i].setRandom();
        }
    }

    /**
     * updates all elements in the list
     *
     * @param dx relative motion in x
     * @param dy relative motion in y
     */
    void update(double dx, double dy) {
        for(UIElement element : elements)
            element.move(dx, dy);
    }

    /**
     * renders all elements in the list
     *
     * @param gc GraphicsContext required for rendering
     */

    void render(GraphicsContext gc) {
        Arrays.sort(elements, (a, b) -> {
            return (int)(100*(b.getZ() - a.getZ()));
        });
        for (UIElement element : elements) {
            element.render(gc);
        }
    }

    /**
     * handles mouse movements and clicks
     *
     * @param x mouse coordinate
     * @param y mouse coordinate
     * @param mode distinguish between selection and dragging
     */
    void mouseMoved(double x, double y, int mode, double dx, double dy) {
        int i=elements.length-1;
        while(i>=0) {
            if(elements[i].contains(x,y) || elements[i].getSelected()==2) {
                if(elements[i].getSelected()==2 && mode==1) {
                    mode=2;
                    elements[i].move(dx, dy);
                }
                elements[i].setSelected(mode);
                i--;
                break;
            }
            else
                elements[i].setSelected(0);
            i--;
        }
        while(i>=0) {
            elements[i].setSelected(0);
            i--;
        }
    }
}