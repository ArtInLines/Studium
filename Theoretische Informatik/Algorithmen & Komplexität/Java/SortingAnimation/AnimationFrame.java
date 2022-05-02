import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.util.*;
import java.util.concurrent.*;
import javax.swing.*;
import javax.swing.event.*;

import static java.lang.Math.*;

enum AlgType {
    BUBBLE_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    MERGE_SORT_NON_RECURSIVE,
    MIN_SORT,
    NAIVE_QUICK_SORT,
    QUICK_SORT,
    ITERATED_INSERTION
};

enum DataType {
    RANDOM,
    ASCENDING,
    DESCENDING
};

/** This panel draws an array and marks two elements in the array. */ 
class ArrayPanel extends JPanel
{
    private Double   mFirst;   // first  value to mark
    private Double   mSecond;  // second value to mark
    private Double[] mArray;   // primary    array ov values
    private Double[] mAux;     // auxilliary array of values
    /**
       Sets the mArray to be painted.
       @param mArray the array of values to display
       @param mFirst the first marked element
       @param mSecond the second marked element
    */
    public void setValues(Double[] values, Double[] aux, Double x, Double y) {
        mArray  = values;
        mAux    = aux;
        mFirst  = x;
        mSecond = y;
        repaint();
    }

    public void paintComponent(Graphics g) {
        if (mArray == null) {
            return;
        }
        // set the background color to a light blue
        setBackground(new Color(0.8F, 0.8F, 1.0F));
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        int width  = getWidth();
        int height = getHeight();
        Rectangle2D borderLine = 
            new Rectangle2D.Double(width + 10, 0, width, 0);
        g2.setPaint(Color.BLACK);
        if (mAux != null) {
            g2.drawLine( 0, height / 2, width, height / 2);
        }
        paintArray(g2, mArray);
        paintArray(g2, mAux);
    }

    /** Paints a given Array.  
        @param g2    a Graphics2D object needed for painting
        @param array the array to be painted
    */     
    private void paintArray(Graphics2D g2, Double[] array)
    {       
        if (array == null) {
            return;
        }
        double width      = getWidth();
        double height     = getHeight();
        double blockWidth = (width - 2) / array.length; 
        double offset     = (array == mArray) ? 0.0 : 0.5 * height;
        double factor     = (mAux  == null)   ? 1.0 : 0.5;
        for (int i = 0; i < array.length; ++i) {
            if (array[i] == null) {
                continue;  // do not paint empty slots of the array
            }
            double length = factor * 0.9 * (array[i] + 0.1) * height;
            Rectangle2D bar = new Rectangle2D.Double(blockWidth * i + 1, 
                                                     offset, 
                                                     blockWidth, 
                                                     length);
            double red   = 2.0 * abs(array[i] - 0.5);
            double green = cos((array[i] - 0.1) * 0.5 * PI);
            double blue  = 0;
            g2.setPaint(new Color((float) red, (float) green, (float) blue));
            g2.fill(bar);
            if (mFirst == array[i] || mSecond == array[i]) {
                BasicStroke stroke = new BasicStroke(1.0F, 
                                                     BasicStroke.CAP_ROUND, 
                                                     BasicStroke.JOIN_ROUND);
                g2.setPaint(Color.BLUE);
                g2.draw(stroke.createStrokedShape(bar));
            } else {
                g2.setPaint(Color.BLACK);
                g2.draw(bar);
            }
        }
    }
}

/** This runnable executes a sort algorithm.
    When two elements are compared, the algorithm
    pauses and updates a panel.
*/
class Sorter implements Runnable
{
    private Double[]   mArray;      // array to be sorted
    private Double[]   mAux;        // auxilliary array, needed by merge sort and 
                                    // used for didactical purposes
    private ArrayPanel mPanel;      // panel to draw on
    private Semaphore  mSemaphore;  // used to control the animation
    private boolean    mRun;        // set to false in single step mode
    private AlgType    mAlgType;    // the sorting algorithm used

    private int        mDelay;

    /** Constructs a Sorter.
        @param values the array to be sorted
        @param panel the panel on which to display the sorting progress
    */     
    public Sorter(Double[] values, ArrayPanel panel, AlgType algType, int delay) {
        mArray     = values;
        mAux       = null;
        mPanel     = panel;
        mSemaphore = new Semaphore(1);
        mRun       = false;
        mAlgType   = algType;
        mDelay     = delay;
        try {
            // prevent the algorithm from starting
            mSemaphore.acquire();
        } catch (InterruptedException exception) {}     
    }

    /** Sets the sorter to "run" mode.
     */
    public void setRun() {
        mRun = true;
        mSemaphore.release();
    }

    /** Sets the sorter to "single step" mode. 
     */
    public void setStep() {
        mRun = false;
        mSemaphore.release();
    }

    /** Sort the array mArray using a special Comparator object.  This object
        does not only compare two values but takes also care of the animation.
        This method is executed when the thread is started.
    */
    public void run() {
        Comparator<Double> comp = new
            Comparator<Double>()
            {
                public int compare(Double x, Double y) {
                    mPanel.setValues(mArray, mAux, x, y);
                    try {
                        if (mRun) {
                            Thread.sleep(mDelay);
                        } else {
                            mSemaphore.acquire();
                        }
                    } catch (InterruptedException exception) {
                        Thread.currentThread().interrupt();
                    }
                    return x.compareTo(y);
                }
            };
        SortingAlgorithm sortAlgorithm = null;
        if (mAlgType == null) {
            mAlgType = AlgType.BUBBLE_SORT;
        }
        switch (mAlgType) {
        case BUBBLE_SORT: 
            sortAlgorithm = new BubbleSortAlgorithm(mArray, comp);
            break;
        case INSERTION_SORT: 
            sortAlgorithm = new InsertionSortAlgorithm(mArray, comp);
            break;
        case MERGE_SORT: 
            sortAlgorithm = new MergeSortAlgorithm(mArray, comp);
            break;
        case MERGE_SORT_NON_RECURSIVE: 
            sortAlgorithm = new MergeSortNRAlgorithm(mArray, comp);
            break;
        case MIN_SORT: 
            sortAlgorithm = new MinSortAlgorithm(mArray, comp);
            break;
        case NAIVE_QUICK_SORT: 
            sortAlgorithm = new NaiveQuickSortAlgorithm(mArray, comp);
            break;
        case QUICK_SORT: 
            sortAlgorithm = new QuickSortAlgorithm(mArray, comp);
            break;
        case ITERATED_INSERTION: 
            sortAlgorithm = new ShellSortAlgorithm(mArray, comp);
            break;
        }
        mAux = sortAlgorithm.getAux();
        sortAlgorithm.sort();
        mPanel.setValues(mArray, mAux, null, null);
    }
}

/** This frame shows the array as it is sorted, together with buttons to single-step the animation
    or to run it without interruption.
*/
public class AnimationFrame extends JFrame
{
    private static final int DEFAULT_WIDTH  = 800;
    private static final int DEFAULT_HEIGHT = 800;

    private Integer    mSize;        // number of array values
    private Integer    mDelay;       // delay in milliseconds
    private Double[]   mArray;       // array of values to be sorted 
    private ArrayPanel mPanel;       // panel for drawing
    private AlgType    mAlgType;     // type of sorting algorithm
    private DataType   mDataType;    // whether we use random numbers or else
    private Random     mRandom;      // random number generator

    /** Get the number of values to be sorted.
     */
    public AnimationFrame() {
        mRandom = new Random(1);
        final JComboBox  comboBox    = 
            new JComboBox(new AlgType[] { AlgType.BUBBLE_SORT, 
                                          AlgType.INSERTION_SORT, 
                                          AlgType.MERGE_SORT,
                                          AlgType.MERGE_SORT_NON_RECURSIVE,
                                          AlgType.MIN_SORT,
                                          AlgType.NAIVE_QUICK_SORT,
                                          AlgType.QUICK_SORT,
                                          AlgType.ITERATED_INSERTION }
                         );
        final JLabel     labelAlg    = new JLabel("Choose the algorithm: ");
        final JLabel     labelDelay  = new JLabel("Delay in milliseconds: ");
        final JTextField delayField  = new JTextField(4);
        final JLabel     labelNumber = new JLabel("Number of values: ");
        final JTextField textField   = new JTextField(4);
        final JPanel     firstPanel  = new JPanel();
        final JComboBox  comboBox2    = 
            new JComboBox(new DataType[] { DataType.RANDOM, 
                                           DataType.ASCENDING, 
                                           DataType.DESCENDING }
                         );
        final JLabel     labelData   = new JLabel("Choose the data: ");

        ActionListener comboListener = new
            ActionListener() 
            {
                public void actionPerformed(ActionEvent e) {
                    mAlgType = (AlgType) comboBox.getSelectedItem();
                }
            };

        ActionListener comboListener2 = new
            ActionListener() 
            {
                public void actionPerformed(ActionEvent e) {
                    mDataType = (DataType) comboBox2.getSelectedItem();
                }
            };

        ActionListener actionListener = new
            ActionListener() 
            {
                public void actionPerformed(ActionEvent e) {
                    remove(firstPanel);
                    startAnimation();
                }
            };

        DocumentListener listener = new 
            DocumentListener()
            {
                public void insertUpdate(DocumentEvent event) {
                    try {
                        mSize = Integer.parseInt(textField.getText().trim());
                    } catch (NumberFormatException e) {}
                }       
                public void removeUpdate(DocumentEvent event) {
                    try {
                        mSize = Integer.parseInt(textField.getText().trim());
                    } catch (NumberFormatException e) {}
                }
                public void changedUpdate(DocumentEvent event) {}
            };

        DocumentListener listener2 = new 
            DocumentListener()
            {
                public void insertUpdate(DocumentEvent event) {
                    try {
                        mDelay = Integer.parseInt(delayField.getText().trim());
                    } catch (NumberFormatException e) {}
                }       
                public void removeUpdate(DocumentEvent event) {
                    try {
                        mDelay = Integer.parseInt(delayField.getText().trim());
                    } catch (NumberFormatException e) {}
                }
                public void changedUpdate(DocumentEvent event) {}
            };

        comboBox.addActionListener(comboListener);
        comboBox2.addActionListener(comboListener2);
        delayField.getDocument().addDocumentListener(listener2);
        textField.getDocument().addDocumentListener(listener);
        textField.addActionListener(actionListener);
        firstPanel.setLayout(new GridLayout(4, 2));
        firstPanel.add(labelAlg);
        firstPanel.add(comboBox);
        firstPanel.add(labelData);
        firstPanel.add(comboBox2);
        firstPanel.add(labelDelay);
        firstPanel.add(delayField);
        firstPanel.add(labelNumber);
        firstPanel.add(textField);
        add(firstPanel, BorderLayout.CENTER);
        setSize(400, 90);
    }
    
    public void startAnimation() 
    {
        mArray = new Double[mSize];
        if (mDataType == null) {
            mDataType = DataType.RANDOM;
        }
        switch (mDataType) {
        case RANDOM:
            // initialize with randoms
            for (int i = 0; i < mArray.length; i++) {
                mArray[i] = mRandom.nextDouble(); 
            }
            break;
        case ASCENDING:
            // initialize with ascending list
            for (int i = 0; i < mArray.length; i++) {
                mArray[i] = (i + 0.0) / mArray.length; 
            }
            break;
        case DESCENDING:
            // initialize with descending list
            for (int i = 0; i < mArray.length; i++) {
                mArray[i] = (mArray.length - i + 0.0) / mArray.length; 
            }
        }
        mPanel = new ArrayPanel();
        add(mPanel, BorderLayout.CENTER);

        Sorter    sorter    = new Sorter(mArray, mPanel, mAlgType, mDelay);
        JButton   runButton = new JButton("Run");     
        RunAction runAction = new RunAction(sorter);
        runButton.setMnemonic('R');
        runButton.addActionListener(runAction);

        JButton    stepButton = new JButton("Step");
        StepAction stepAction = new StepAction(sorter);
        stepButton.setMnemonic('S');
        stepButton.addActionListener(stepAction);

        JPanel buttons = new JPanel();
        buttons.add(runButton);
        buttons.add(stepButton);     
        add(buttons, BorderLayout.NORTH);
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        stepButton.requestFocus();

        InputMap  inputMap  = buttons.getInputMap(JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);
        ActionMap actionMap = buttons.getActionMap();
        inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "step");
        actionMap.put("step", stepAction);

        Thread thread = new Thread(sorter);
        thread.start();
    }
    
    class RunAction extends AbstractAction 
    {
        Sorter mSorter;
        
        RunAction(Sorter sorter) {
            mSorter = sorter;   
        }
        
        public void actionPerformed(ActionEvent event) {
            mSorter.setRun();
        }
    }

    class StepAction extends AbstractAction
    {       
        Sorter mSorter;
        
        StepAction(Sorter sorter) {
            mSorter = sorter;
        }
        
        public void actionPerformed(ActionEvent event) {
            mSorter.setStep();
        }
    }

    public static void main(String[] args) {
        JFrame frame = new AnimationFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}


