import javax.swing.*;
import java.awt.*;
import java.util.Vector;

public class DrawSkylinePanel extends JPanel {     // Class DrawSkylinePanel draws line between points


    public DrawSkylinePanel(Vector<Point> points, int maxHeight) { // constructor for taking points and max height
        this.points = points;
        this.maxHeight = maxHeight;
    }

    private Vector<Point> points;
    private int maxHeight;

    public void paintComponent(Graphics g) {      // override JPanel functions
        super.paintComponent(g);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(5));      // sets line stroke

        for (int i = 0; i < points.size() - 1; i++) { // drawing line
            g2.drawLine(25 * points.get(i).getX(), (maxHeight + 1) * 25 - (25 * points.get(i).getY()),
                    25 * points.get(i + 1).getX(), (maxHeight + 1) * 25 - (25 * points.get(i + 1).getY()));

        }
    }
}
