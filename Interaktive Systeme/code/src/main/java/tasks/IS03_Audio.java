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
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.util.Duration;

/*
 * Aufgabe IS-03: Interaktive Audioausgabe
 *
 * @author Eckhard Kruse
 */
public class IS03_Audio extends Application {

    ImageView img;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {

        Group root = new Group();
        Scene scene = new Scene(root);

        img= new ImageView("File:scene.jpg"); // Load image
        root.getChildren().add(img);

        InteractiveAudioOutput audioOutput = new InteractiveAudioOutput();

        // Handlers to resize window
        scene.widthProperty().addListener(evt -> draw(scene));
        scene.heightProperty().addListener(evt -> draw(scene));
        scene.addEventHandler(MouseEvent.MOUSE_MOVED, evt -> audioOutput.mouseMoved(evt));

        stage.setTitle("Interaktive Systeme - IS03 - Interactive Audio Output");
        stage.setScene(scene);
        stage.show();

        Timeline timeline = new Timeline(new KeyFrame(
                Duration.millis(50), evt -> audioOutput.audioUpdate()));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();

    }

    /**
     * Bild ggf. skalieren
     *
     *  @param scene
     */
    private void draw(Scene scene) {
       // TODO: Verschiedene Oberflächen mit verschiedenen Klangeigenschaften
       img.setFitWidth(scene.widthProperty().doubleValue());
       img.setFitHeight(scene.heightProperty().doubleValue());
    }
}
