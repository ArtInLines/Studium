package tasks;
/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.util.Random;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

/*
 * Aufgabe IS-01: Einfache Anwendung + Farbige Ausgabe
 *
 * @author Eckhard Kruse
 */
public class IS01_Colors extends Application {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {

        Group root = new Group();
        Canvas canvas = new Canvas();
        root.getChildren().add(canvas);

        Scene scene = new Scene(root, 600, 500);

        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Handlers to resize window
        scene.widthProperty().addListener(evt -> draw(gc));
        scene.heightProperty().addListener(evt -> draw(gc));

        canvas.widthProperty().bind(scene.widthProperty());
        canvas.heightProperty().bind(scene.heightProperty());

        draw(gc);

        stage.setTitle("Interaktive Systeme - IS01 - Colors");
        stage.setScene(scene);
        stage.show();
    }

    /**
     * Redraw the entire window
     *
     *  @param gc GraphicsContext needed for drawing
     */
    private void draw(GraphicsContext gc) {
        gc.setFill(Color.valueOf("2c2c2c"));
        gc.fillRect(0, 0, gc.getCanvas().getWidth(), gc.getCanvas().getHeight());

        double canvasWidth = gc.getCanvas().getWidth();
        double canvasHeight = gc.getCanvas().getHeight();
        for (int i = 0; i < 5; i++) {
            double w = canvasWidth/3;
            double h = canvasHeight/6;
            double fontsize = canvasWidth / 30;
            double wpad = (canvasWidth - 2*w) / 3;
            double hpad = (canvasHeight - 5*h) / 7;
            renderElement(gc, i, canvasWidth/2 - w - wpad/2, (i+1)*hpad + i*h, w, h, fontsize);
            renderElement(gc, i, canvasWidth/2 + wpad/2,     (i+1)*hpad + i*h, w, h, fontsize);
        }
    }

    /**
     * Draw single element
     *
     *  @param gc GraphicsContext needed for drawing
     *  @param myRnd random generator object used for colors and other parameters
     */
    private void renderElement(GraphicsContext gc, int cnt, double x, double y, double w, double h, double fontsize) {
        gc.setFill(Color.valueOf("1f1f1f"));
        gc.fillRoundRect(x, y, w, h, 8, 8);

        gc.setFill(new LinearGradient(0, 0, 0.2, 0.5, true, CycleMethod.REFLECT,
                    new Stop(0.0, Color.valueOf("f24fd4")),
                    new Stop(1.0, Color.valueOf("ef09c5")) ));
        gc.fillRoundRect(x + 4, y + 4, w - 8, fontsize, 8, 8);

        gc.setFill(new LinearGradient(0, 0, 0.5, 0.1, true, CycleMethod.REFLECT,
                    new Stop(0.0, Color.valueOf("2492f2")),
                    new Stop(1.0, Color.valueOf("0a8bfc")) ));

        gc.fillRoundRect(x + 8, y + 8 + fontsize, w - 16, h - 16 - fontsize, 8, 8);

        gc.setFill(Color.valueOf("111111"));
        gc.setFont(Font.font("Arial", FontWeight.BLACK, FontPosture.ITALIC, fontsize));
        gc.fillText("Title" + cnt, x + 4, y + fontsize);

        gc.setFill(Color.valueOf("222222"));
        fontsize/=2;
        gc.setFont(new Font("Arial", fontsize));
        for (int i = 1; i < h/fontsize-4; i++)
            gc.fillText(i + ". text content", x+20, y+(i+3)*fontsize);
    }

}
