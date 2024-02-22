package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */
import java.util.ArrayList;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;

/*
 * Aufgabe IS-05: Objekte mit physikalischen Eigenschaften (Masse, Trägheit...)
 *
 * @author Eckhard Kruse
 */
public class IS05_Physikobjekte extends Application {

    private ArrayList<PhysicalElement> elements;

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

        elements = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            PhysicalElement el= new PhysicalElement();
            el.setRandomPosition(1200, 800);
            elements.add(el);
            root.getChildren().add(el.getSceneObject());
        }

        Timeline timeline = new Timeline(new KeyFrame(
                Duration.millis(50), evt -> timerEvent(scene)));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();

        stage.setTitle("Interaktive Systeme - IS05 - Physikobjekte");
        stage.setScene(scene);
        stage.show();
    }

    /**
     * Timerbasierte Aktualisierung aller Elemente
     *
     * @param scene Scene
     */
    public void timerEvent(Scene scene) {
        for(PhysicalElement el : elements)
            el.update(scene.getWidth(), scene.getHeight());
    }
}
