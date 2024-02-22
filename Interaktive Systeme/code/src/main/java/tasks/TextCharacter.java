package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

/**
 * Store single character of typed text including rendering hints and render method
 *
 * @author Eckhard Kruse
 */
class TextCharacter {
    public String myChar;
    private double size;
    public boolean pressed;
    private Color col;
    public static double MAX_SIZE = 60;

    TextCharacter(String c) {
        myChar=c;
        size=20.;
        pressed = true;
        col = Color.GREY;
    }

    TextCharacter(String c, boolean diffColor) {
        myChar=c;
        size=20.;
        pressed = true;
        if (diffColor) col = Color.RED;
        else col = Color.GREY;
    }

    /**
     * Incrase character size or other change of display style,
     * as long as key is pressed
     */
    void grow() {
        size += 0.5;
        if (size > MAX_SIZE) size = MAX_SIZE;
    }

    /**
     * key has been released, finalize character / rendering
     *
     */
    void released() {
        pressed = false;
    }

    /**
     * Draw character
     *
     * @param gc GraphicsContext is required for rendering
     * @param x x-coordinate to display character
     * @param y y-coordinate to display character
     * @return x-coordinate for next character, based on size of current character
     */
    double render(GraphicsContext gc, double x, double y) {

        Font f = new Font(size);

        final Text t = new Text(myChar);
        t.setFont(f);
        double width=t.getLayoutBounds().getWidth();

        gc.setFont(f);
        gc.setFill(col);
        gc.fillText(myChar, x, y);

        return x + width;
    }

}
