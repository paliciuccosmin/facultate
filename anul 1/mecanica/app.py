import pygame
import math

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

def main():
    # Initialize Pygame
    pygame.init()

    # Set the dimensions of the screen
    size = (800, 600)
    screen = pygame.display.set_mode(size)

    # Set the caption of the window
    pygame.display.set_caption("Spiral Animation")

    # Set the starting values for the spiral and the bar
    omega0 = 1.0
    t = 0
    v0 = 45
    angle = 0

    # Start the main loop
    done = False
    clock = pygame.time.Clock()
    while not done:
        # Check for events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True

        # Calculate the position of the point on the spiral
        x = size[0] / 2 + v0 * t * math.cos(omega0 * t)
        y = size[1] / 2 + v0 * t * math.sin(omega0 * t)

        # Clear the screen
        screen.fill(WHITE)

        # Draw the static cartesian xoy axes
        pygame.draw.line(screen, BLACK, (size[0] / 2, 0), (size[0] / 2, size[1]), 2)
        pygame.draw.line(screen, BLACK, (0, size[1] / 2), (size[0], size[1] / 2), 2)

        # Draw the point
        pygame.draw.circle(screen, BLACK, (int(x), int(y)), 10)

        # Calculate the position of the end of the rotating bar
        bar_length = 50
        bar_center_x = size[0] / 2
        bar_center_y = size[1] / 2
        bar_end_x = bar_center_x + bar_length * math.cos(math.radians(angle))
        bar_end_y = bar_center_y + bar_length * math.sin(math.radians(angle))

        # Draw the rotating bar
        pygame.draw.line(screen, BLACK, (int(bar_center_x), int(bar_center_y)), (int(bar_end_x), int(bar_end_y)), 5)

        # Update the time and angle
        t += 0.01
        angle += 1

        # Update the screen
        pygame.display.flip()

        # Limit the frame rate
        clock.tick(60)

    # Quit Pygame
    pygame.quit()

if __name__ == "__main__":
    main()
