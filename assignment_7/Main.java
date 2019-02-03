import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {

        Skyline mySkyline = new Skyline("data.txt");                          // creating new Skyline object

        mySkyline.printSkylinePoints();                                                // printing skyline points to output

        DrawSkylinePanel skylinePanel = new DrawSkylinePanel(mySkyline.getPoints(), mySkyline.getMaxHeight()); // creating new skylinePanel and pass points and max height by argument
        skylinePanel.setBackground(Color.white);                                              // changes skylinePanel background color

        JFrame skylineFrame = new JFrame();
        skylineFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);                    // sets jFrames close option

        skylineFrame.add(skylinePanel);                                                        // add the skylinePanel to the frame
        skylineFrame.setSize(mySkyline.getTotalWidth() * 25, (mySkyline.getMaxHeight() + 2) * 25);   // set the size of the frame
        skylineFrame.setVisible(true);                                                  // make the frame visible

    }

}
