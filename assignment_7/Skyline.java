import java.io.*;
import java.util.Scanner;
import java.util.Vector;

// class Skyline keeps skyline data end does some operation for drawing skyline

public class Skyline {

    private String fileName;                    // keeps file name
    private Vector<Rectangle> rectangles;       // keeps all rectangles in the visualization
    private Vector<Integer> positionLine;       // keeps rectangles height by location on the line (visualization width line)
    private long positionLineWidth;             // visualization width
    private Vector<Point> points;               // keeps skyline corner points
    private int maxHeight;                      // keeps max height of the rectangles
    private int totalWidth;                     // total rectangles width is position line width

    public Skyline() {                          // default constructor

        positionLineWidth = 0;

        rectangles = new Vector<>();            // keeping memory
        positionLine = new Vector<>();
        points = new Vector<>();

    }

    public Skyline(String filename) {           // constructor for filename

        positionLineWidth = 0;
        fileName = filename;

        rectangles = new Vector<>();            // keeping memory
        positionLine = new Vector<>();
        points = new Vector<>();

        readFile();                             // calling functions for finding skyline point
        findLineWidth();
        fillHeightsToLine();
        findSkylinePoints();
        findMaxHeight();

    }

    private void readFile() {                   // reads file and fill rectangles vector


        try (Scanner scanner = new Scanner(new File(fileName))) {       // creating new scanner for reading file in try

            while (scanner.hasNext()) {                                 // if is there scanner next

                int width = scanner.nextInt();                          // reading width
                int height = scanner.nextInt();                         // reading height
                int position = scanner.nextInt();                       // reading position

                rectangles.add(new Rectangle(width,height,position));   // creating new Rectangle object and adding rectangles vector

            }


        } catch (IOException e) {               // input output exception if any error is occur
            e.printStackTrace();                // print error tree
        }


    }

    private void findLineWidth() {              // finds line width value by rectangles left positions

        for (int i = 0; i < rectangles.size(); ++i) {

            if (rectangles.get(i).getRightPosition() + 1 > positionLineWidth) {   // comparing for max value and update new value

                positionLineWidth = (rectangles.get(i).getRightPosition() + 1);

            }
        }

        totalWidth = (int) positionLineWidth;           // assigning total value

        for (int i = 0; i < positionLineWidth; i++) {   // resetting position line width for new values
            positionLine.add(0);
        }

    }

    private void fillHeightsToLine() {          // finds max heights by rectangle position and fill position line vector

        for (int k = 0; k < rectangles.size(); ++k) {

            // for loop start rectangle left position to rectangle right position
            for (int i = rectangles.get(k).getPosition(); i < rectangles.get(k).getRightPosition(); ++i) {
                // i using location of rectangles height in the position line
                if (positionLine.get(i) < rectangles.get(k).getHeight()) {  // comparing previous height

                    positionLine.set(i, rectangles.get(k).getHeight());
                }

            }

        }

    }

    private void findSkylinePoints() {          // finds skyline points and fills them to points vector

        for (int l = 0; l < positionLine.size() -1 ; ++l) {             // compares position l and l + 1 index so for runs away to size - 1 index

              if (positionLine.get(l) < positionLine.get(l + 1)) {      // if height in l < height in l+1 this is a skyline corner point

                  points.add(new Point(l + 1, positionLine.get(l)));
                  points.add(new Point(l + 1, positionLine.get(l + 1)));
              }

              if (positionLine.get(l) > positionLine.get(l + 1)) {       // if height in l > height in l+1 this is a skyline corner point

                  points.add(new Point(l + 1, positionLine.get(l)));
                  points.add(new Point(l + 1, positionLine.get(l + 1)));
              }

        }

    }

    public void printSkylinePoints() {          // prints skyline points to output

        for (int m = 0; m < points.size(); ++m) {

            System.out.print("(" + points.get(m).getX() + ", " + points.get(m).getY() + ")");
            if (m < points.size()-1){
                System.out.print(", ");
            }
        }

    }

    private void findMaxHeight(){               // finds max height of rectangles

        maxHeight = 0;

        for (int i = 0; i < rectangles.size(); i++) {
            if(rectangles.get(i).getHeight() > maxHeight){
                maxHeight = rectangles.get(i).getHeight();
            }
        }

    }

    public int getTotalWidth() { return totalWidth; }

    public int getMaxHeight() { return maxHeight; }

    public Vector<Point> getPoints() { return points; }
}
