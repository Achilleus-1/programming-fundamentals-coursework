// Maintenance compatibility helper; not the original course DrawingPanel.
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

public final class DrawingPanel {
    private final BufferedImage image;
    private JPanel canvas;
    private Color background = Color.WHITE;

    public DrawingPanel(int width, int height) {
        image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        clearImage();
        Runnable setup = () -> {
            canvas = new JPanel() {
                @Override protected void paintComponent(Graphics graphics) {
                    super.paintComponent(graphics);
                    graphics.drawImage(image, 0, 0, null);
                }
            };
            canvas.setPreferredSize(new java.awt.Dimension(width, height));
            JFrame frame = new JFrame("Coursework drawing demo");
            frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            frame.add(canvas);
            frame.pack();
            frame.setVisible(true);
            Timer timer = new Timer(33, event -> canvas.repaint());
            timer.start();
            frame.addWindowListener(new java.awt.event.WindowAdapter() {
                @Override public void windowClosed(java.awt.event.WindowEvent event) {
                    timer.stop();
                }
            });
        };
        try {
            if (SwingUtilities.isEventDispatchThread()) setup.run();
            else SwingUtilities.invokeAndWait(setup);
        } catch (Exception error) {
            throw new IllegalStateException("Cannot create drawing window", error);
        }
    }

    public Graphics getGraphics() { return image.getGraphics(); }
    public void setBackground(Color color) { background = color; clear(); }
    private void clearImage() {
        Graphics graphics = image.getGraphics();
        graphics.setColor(background);
        graphics.fillRect(0, 0, image.getWidth(), image.getHeight());
        graphics.dispose();
    }
    public void clear() { clearImage(); if (canvas != null) canvas.repaint(); }
    public void sleep(int milliseconds) {
        try { Thread.sleep(milliseconds); }
        catch (InterruptedException error) { Thread.currentThread().interrupt(); }
        canvas.repaint();
    }
}
