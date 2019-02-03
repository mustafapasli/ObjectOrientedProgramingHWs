// class Rectangle keeps rectangle information and rectangle operations
public class Rectangle {

    private int width;
    private int height;
    private int position; // right position
    private int rightPosition; // position + width

    public Rectangle(int width, int height, int position) {
        this.width = width;
        this.height = height;
        this.position = position;
        rightPosition = position + width;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public int getPosition() {
        return position;
    }

    public int getRightPosition() {
        return rightPosition;
    }
}
