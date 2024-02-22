package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */
import java.util.ArrayList;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;

/*
 * Aufgabe IS-04: Neue Konzepte zur Tastaturnutzung
 *
 * @author Eckhard Kruse
 */
public class IS04_Keyboard extends Application {

    ArrayList<TextCharacter> typedText;
    ArrayList<TextCharacter> nextKeys;

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

        Scene scene = new Scene(root, 800, 500);

        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Handlers to resize window
        scene.widthProperty().addListener(evt -> draw(gc));
        scene.heightProperty().addListener(evt -> draw(gc));

        canvas.widthProperty().bind(scene.widthProperty());
        canvas.heightProperty().bind(scene.heightProperty());

        typedText = new ArrayList<>();
        nextKeys  = new ArrayList<>();

        draw(gc);

        Timeline timeline = new Timeline(new KeyFrame(Duration.millis(10), evt -> timerEvent(gc)));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();

        scene.addEventHandler(KeyEvent.KEY_PRESSED, evt -> keyPressed(gc, evt));
        scene.addEventHandler(KeyEvent.KEY_RELEASED, evt -> keyReleased(gc, evt));

        stage.setTitle("Interaktive Systeme - IS04 - Keyboard");
        stage.setScene(scene);
        stage.show();
    }

    private void draw(GraphicsContext gc) {
       	gc.setFill(new Color(0.1, 0.1, 0.2, 1.0));
        gc.fillRect(0, 0, gc.getCanvas().getWidth(), gc.getCanvas().getHeight());

        double x_start = 10;
        double y_start = 100;
        double y_offset = TextCharacter.MAX_SIZE + 10;
    	double x = x_start, y = y_start;

        for (TextCharacter typedChar: typedText) {
            x = typedChar.render(gc, x, y);
            if(x > gc.getCanvas().getWidth() - x_start) {
                x = 10;
                y += y_offset;
            }
        }
    }

    /**
     * timer event handler, updates and renders elements
     *
     * @param gc GraphicsContext to be used for rendering
     */
    private void timerEvent(GraphicsContext gc) {
        int n = typedText.size();
        TextCharacter c;
        if (n > 0 && (c = typedText.get(n - 1)).pressed) c.grow();
        draw(gc);
    }

    /**
     * key event handler
     *
     * @param gc GraphicsContext to be used for rendering
     * @param key Keyboard event
     */
    private void keyPressed(GraphicsContext gc, KeyEvent key) {
        int n = typedText.size();
        KeyCode k = key.getCode();
        if (!k.isLetterKey() && !k.isWhitespaceKey() && !k.isDigitKey()) return;
        String c = k.getChar();
        if (n > 0 && typedText.get(n - 1).pressed) {
            if (typedText.get(n - 1).myChar != c) nextKeys.add(new TextCharacter(c, true));
            return;
        }
        typedText.add(new TextCharacter(c));
        draw(gc);
    }

    private void keyReleased(GraphicsContext gc, KeyEvent key) {
        int n = typedText.size();
        if (n > 0) typedText.get(n - 1).released();
        if (nextKeys.size() > 0) {
            typedText.add(nextKeys.get(0));
            nextKeys.remove(0);
        }
        draw(gc);
    }
}
