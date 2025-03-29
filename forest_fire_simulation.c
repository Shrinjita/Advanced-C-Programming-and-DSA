#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY 0
#define TREE 1
#define BURNING 2

int main() {
  // Seed random number generator
  srand(time(NULL));

  // Get forest dimensions and number of exits
  int rows, cols, num_exits;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);
  printf("Enter the number of exits: ");
  scanf("%d", &num_exits);

  // Allocate memory for the forest map
  int** forest_map = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; ++i) {
    forest_map[i] = (int*)malloc(cols * sizeof(int));
  }

  // Create the forest map
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      forest_map[i][j] = rand() % 2;  // Randomly assign TREE or EMPTY
    }
  }

  // Define exit locations
  int exits[num_exits][2];
  for (int i = 0; i < num_exits; ++i) {
    printf("Enter the coordinates of exit %d (row col): ", i + 1);
    scanf("%d %d", &exits[i][0], &exits[i][1]);
  }

  // Print the initial forest map
  printf("\nForest Map:\n");
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      printf("%d ", forest_map[i][j]);
    }
    printf("\n");
  }

  // Start the fire
  int fire_row = rand() % rows;
  int fire_col = rand() % cols;
  forest_map[fire_row][fire_col] = BURNING;
  printf("\nFire starts at position (%d, %d)!\n", fire_row, fire_col);

  // Simulate fire spread until no more trees can burn
  while (1) {
    int burnt_trees = 0;
    
    // Spread fire
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (forest_map[i][j] == BURNING) {
          // Check adjacent cells within bounds
          if (i > 0 && forest_map[i - 1][j] == TREE) {
            forest_map[i - 1][j] = BURNING;
            burnt_trees++;
          }
          if (i < rows - 1 && forest_map[i + 1][j] == TREE) {
            forest_map[i + 1][j] = BURNING;
            burnt_trees++;
          }
          if (j > 0 && forest_map[i][j - 1] == TREE) {
            forest_map[i][j - 1] = BURNING;
            burnt_trees++;
          }
          if (j < cols - 1 && forest_map[i][j + 1] == TREE) {
            forest_map[i][j + 1] = BURNING;
            burnt_trees++;
          }
        }
      }
    }

    // Print the forest map after fire spread
    printf("\nForest Map After Fire:\n");
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        printf("%d ", forest_map[i][j]);
      }
      printf("\n");
    }

    // Check if no more trees to burn
    if (burnt_trees == 0) {
      break;
    }
  }

  // Generate evacuation plan for each burning tree
  printf("\nEvacuation Plan:\n");
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (forest_map[i][j] == BURNING) {
        // Find the nearest exit for this burning tree
        int min_dist = rows + cols;  // Initialize minimum distance to a large value
        int exit_row, exit_col;
        for (int k = 0; k < num_exits; ++k) {
          int dist = abs(i - exits[k][0]) + abs(j - exits[k][1]);
          if (dist < min_dist) {
            min_dist = dist;
            exit_row = exits[k][0];
            exit_col = exits[k][1];
          }
        }
        printf("Evacuate tree at (%d, %d) to exit at (%d, %d)\n", i, j, exit_row, exit_col);
      }
    }
  }

  // Free memory allocated for forest map
  for (int i = 0; i < rows; ++i) {
    free(forest_map[i]);
  }
  free(forest_map);

  return 0;
}
