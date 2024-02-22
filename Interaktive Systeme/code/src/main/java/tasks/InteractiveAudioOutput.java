package tasks;

/*
 * Beispielcode VL Interaktive Systeme, Angewandte Informatik, DHBW Mannheim
 *
 * Prof. Dr. Eckhard Kruse
 */

import java.io.File;
import java.io.IOException;
import javafx.scene.input.MouseEvent;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;
import javax.sound.sampled.UnsupportedAudioFileException;

/**
 * Timer-gesteuerte Audioausgabe, unter Berücksichtigung der Mausbewegung
 *
 * @author Eckhard Kruse
 */
class InteractiveAudioOutput {

    double actX, actY, oldX, oldY;    // Alte + aktuelle Mausposition
    double mouse_val1, mouse_val2;    // Mausbewegungsabhängige Werte

    static double amplitude_fact_min = 0.3;
    static double amplitude_fact_max = 1.0;
    static double freq_fact_min = 1.0;
    static double freq_fact_max = 2.0;

    // Audio data
    SourceDataLine line;
    byte val;
    byte[] wavBuffer;
    byte[] wavOutput;
    int bufPointer;

    final int bufLen=4410;    // TODO: Welche Funktion hat dieser Parameter?

    InteractiveAudioOutput() {

        wavOutput=new byte[bufLen];

        // Werte mit Defaults initialisieren
        oldX=0; oldY=0;
        mouse_val1=mouse_val2=amplitude_fact_min;
        bufPointer=0;
        try {
            // TODO: use different audio files for different screen regions
            // open audio file and read it into byte buffer
            File file = new File("water.wav");
            AudioInputStream stream = AudioSystem.getAudioInputStream(file);
            AudioFormat format = stream.getFormat();
            System.out.println("Wav File: " + format.getSampleRate() + " Hz, " + format.getSampleSizeInBits() + " Bits pro Sample"
                    + " FrameSize: " + format.getFrameSize());
            wavBuffer = new byte[(int) (format.getFrameSize() * stream.getFrameLength())];
            stream.read(wavBuffer);
            DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);
            line = (SourceDataLine) AudioSystem.getLine(info);
            line.open(format, bufLen * 2);
            line.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            e.printStackTrace();
        }
    }

    double lerp(double t, double min, double max) {
        return min + t*(max - min);
    }

    /**
     * Event-Handler für Mausbewegung
     * TODO 2: Je nach Mausposition im Bild -> verschiedene Klänge verwenden
     *
     * @param e MouseEvent mit Koordinaten
     */
    void mouseMoved(MouseEvent e) {
    	// Mausgeschwindigkeit -> Lautstärke
    	// Maus Y-Koordinate -> Tonhöhe
        actX=e.getX();
        actY=e.getY();
        double dx = Math.abs(actX - oldX);
        double dy = Math.abs(actY - oldY);
        mouse_val1 = Math.max(Math.min(Math.sqrt(dx*dx + dy*dy)/30.0, 1.0), 0.0);
        oldX=actX;
        oldY=actY;
    }

    /**
     * Timer-gesteuerte Audioausgabe
     */
    void audioUpdate() {
        if(line.available()>=bufLen) { // genug Platz für neue Daten
            mouse_val2 += Math.signum(mouse_val1 - mouse_val2) * lerp(0.75, 0, Math.abs(mouse_val1 - mouse_val2));
            mouse_val2 = Math.max(Math.min(mouse_val2, 1.0), 0.0);
            double amplitude_fact = lerp(mouse_val2, amplitude_fact_min, amplitude_fact_max);
            double freq_fact = lerp(mouse_val2, freq_fact_min, freq_fact_max);
            double freq_i = 0.0;
            System.out.println(freq_fact);

    		for(int i=0; i<bufLen; i++) {
    			// TODO: Lineare Interpolation zwischen 2 Samples
                freq_i += freq_fact;
                int nextBufPointer = ((int)freq_i)%(wavBuffer.length-1);
    			int val = (int)lerp(0.5, wavBuffer[bufPointer]&255, wavBuffer[nextBufPointer]&255);
	    		bufPointer = nextBufPointer;
                        // val = 128 ist Nulllinie, Wertebereich 0-255

    			// TODO: Y -> variable Schrittweite -> Tonhöhe
                val = ((int)(amplitude_fact*(val - 128)) + 128)&255;
	        	wavOutput[i]=(byte)val;
	    	}
    		line.write(wavOutput,0,bufLen);
    	}
        mouse_val1*=0.5; // Fade out
    }
}

