package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.util.Random;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;

/**
 * Single UI Element, renders itself based on coordinates and other data
 *
 * @author Eckhard Kruse
 */
class UIElement {

    private double x, y, z;    // Position in 3D space: x and y from -0.5 to 0.5,  z from 0 to 1
    private double scalePos;   // Factor to transform 3D and screen coordinates
    private String txt;
    private Color col;

    private double dx, dy, dz;
    private Rectangle shape;
    private int selected;  // 0: not, 1: touched, 2: clicked

    private final double focusLength=0.3;            // perspektische Skalierung
    private final double focusLengthTranslate=2.;   // perspektivische Verschiebung

    // Theme: Colors for object and shadows
    private static final Color[] colorObjects =
        { new Color(0.6, 0.9, 0.4, 1.0), new Color(0.7, 0.8, 0.4, 1.0), new Color(0.3, 0.7, 0.5, 1.0) };
    private static final Color colorShadow = new Color(0.15, 0.2, 0.4, 1.0);
    public static final Color colorBackground = new Color(0.3, 0.4, 0.6, 1.0);

    UIElement() {
        shape = new Rectangle();
        scalePos=1.f; // to prevent div by zero
    }

    int getSelected() {
        return selected;
    }

    void setSelected(int selected) {
        this.selected = selected;
    }

    double getZ() {
        return z;
    }

    void setZ(double z) {
        this.z = z;
    }

    /**
     * Initialize Element with Random data
     *
     */
    void setRandom() {

        Random r = new Random();
        x = r.nextDouble() - 0.5;
        y = r.nextDouble() - 0.5;
        z = r.nextDouble();

        dx = (r.nextDouble() - 0.5) / 100.;
        dy = (r.nextDouble() - 0.5) / 100.;
        dz = (r.nextDouble() / 100.);

        txt = ""+r.nextInt(100);
        col = colorObjects[r.nextInt(3)];
    }

    /**
     * Move element according to mouse movement
     *
     * @param mdx relative movement in x direction
     * @param mdy relative movement in y direction
     */
    void move(double mdx, double mdy) {
       if (selected > 0) {
            // z+=0.02f;   // Simple example: slowly increase z distance to infinity
            if (z >= 1.0f) z = 1.0f;
            x+=mdx/scalePos;
            y+=mdy/scalePos;
        }
    }

    /**
     * Check if mouse click (with coordinates x,y) hits object
     *
     * @param x mouse coordinate
     * @param y mouse coordinate
     */
    boolean contains(double x, double y)
    {
        return shape.contains(x, y);
    }

    /**
     * Transform given color to render color based on object data (z coordinate etc.)
     *
     * @param c Color to be transformed
     * @return resulting color
     */
    Color transformColor(Color c)
    {
        return c.deriveColor(0, 1-z*0.7, 1-z*0.7, 1.0);
    }

    /**
     * renders the UIElement
     *
     * @param gc GraphicsContext required for rendering
     */
    void render(GraphicsContext gc)
    {
        final double canvasWidth = gc.getCanvas().getWidth();
        final double canvasHeight = gc.getCanvas().getHeight();

        double scaleSize = java.lang.Math.max(canvasWidth, canvasHeight);
        // use z to calculate perspective object position and size
        scalePos = scaleSize * 0.9 * (1 + focusLengthTranslate) / (z + focusLengthTranslate);
        scaleSize = scaleSize * (1 + focusLength) / (z + focusLength);

	// Object position (center) on screen, width + height
        // Use scaleSize / scalePos to simulate 3D perspective
        double xc = x * scalePos + canvasWidth/2;
        double yc = y * scalePos + canvasHeight/2;
        double ow = scaleSize / 15;
        double oh = scaleSize / 30;

        // Store current object boundaries for click detection
        shape = new Rectangle(xc-ow/2, yc-oh/2, ow, oh);

        // TODO: render depth clues based on z
        gc.setFill(transformColor(selected==0? col : (selected==1? Color.BLUE : Color.WHITE)));
        gc.fillRoundRect(xc - ow / 2, yc - oh / 2, ow, oh, ow/5, ow/5);

        gc.setFill(transformColor(col));
        gc.fillRoundRect(xc - ow / 2+4, yc - oh / 2+4, ow-8, oh-8, ow/5-4, ow/5-4);

        gc.setFill(transformColor(selected==1? Color.BLUE : Color.WHITE));
        gc.setFont(new Font("Arial", scaleSize*0.015));  // TODO: Use scaleSize to adjust font size
        gc.fillText(txt, xc - ow/4, yc+oh/3);
    }

    // TODO Render shadows
}
