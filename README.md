# Graph Isomorphism Recognition Algorithm

A Qt-based desktop application for building two undirected graphs, visualizing them, and checking whether they are isomorphic.

## Overview

This project provides an interactive GUI to:

- create two graphs with a chosen number of vertices,
- add edges manually for each graph,
- visualize both graphs side-by-side,
- test graph isomorphism,
- export each graph view as an image.

The core check uses a permutation-based brute-force isomorphism test on adjacency matrices.

## Features

- **Dual graph workspace**: manage Graph 1 and Graph 2 independently.
- **Adjacency-matrix representation**: graphs are stored as `std::vector<std::vector<int>>`.
- **Graph rendering**: vertices are placed in a circular layout and edges are drawn between connected vertices.
- **Isomorphism checker**: reports whether the two graphs are isomorphic.
- **Image export**: save graph visualizations as PNG files.

## How the Isomorphism Check Works

The implementation compares all vertex permutations:

1. Build an identity permutation of vertex indices.
2. For each permutation, compare every pair `(i, j)` in Graph 1 against `(perm[i], perm[j])` in Graph 2.
3. If all adjacency values match, the graphs are isomorphic.
4. Otherwise, continue until all permutations are exhausted.

### Complexity

- Time complexity: **O(n! · n²)** for `n` vertices.
- Space complexity: **O(n²)** for adjacency matrices, plus permutation storage.

This is suitable for small graphs and educational/demo use.

## Project Structure

```text
Main.cpp            # Application entry point
mainwindow.h        # Main window class declaration
mainwindow.cpp      # UI event handlers, drawing, and isomorphism logic
mainwindow.ui.qml   # UI form definition (Qt Design Studio format)
```

## Requirements

- C++ compiler with C++11+ support
- Qt framework (Qt Widgets, Qt GUI modules)
- A Qt project configuration (for example via Qt Creator) that includes these source files

## Building and Running

Since this repository currently contains source files without a committed `.pro`/`CMakeLists.txt`, the usual flow is:

1. Open/create a Qt Widgets application project in **Qt Creator**.
2. Add the repository source files (`Main.cpp`, `mainwindow.h`, `mainwindow.cpp`) to the project.
3. Ensure UI integration matches your project setup (`ui_mainwindow.h` generation and form wiring).
4. Build and run from Qt Creator.

## Usage

1. Set the number of vertices for Graph 1 and Graph 2.
2. Click **Generate Graph** for each graph.
3. Add edges by selecting vertex indices and clicking **Add Edge**.
4. Click **Check Isomorphism** to compare the graphs.
5. Optionally click **Save Image** to export graph views.

## Notes and Limitations

- Graphs are treated as **undirected** (edge `(u, v)` is mirrored to `(v, u)`).
- Self-loops and multi-edges are not explicitly modeled.
- The brute-force algorithm does not scale well for large vertex counts.

## Future Improvements

- Add canonical labeling / partition refinement to speed up checks.
- Add input validation to prevent duplicate/self-loop edge issues (if desired).
- Add project build files (`CMakeLists.txt` or `.pro`) for reproducible builds.
- Add tests for correctness on known isomorphic/non-isomorphic graph pairs.
