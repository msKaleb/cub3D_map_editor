# A simple map editor for 42school cub3D project

The program uses the same graphics library that the project itself (minilibx), so that it can be easily compiled

### Clone and compilation:
```
$ git clone https://github.com/msKaleb/cub3D_map_editor/
$ cd cub3D_map_editor/
$ make
```
### Usage:
You can type `./editor --help` to get the instructions:
```
Usage: ./editor map_name [map_size=10]
Generates a square map (by default 10x10) to be used with cub3D project.
Recommended values range from 10 to 50.
  map_name: Name of the file to be generated.
  map_size: Optional. Defines the area of the map (e.g. 40x40).

Controls:
	Left click: wall square (hold to 'paint')
	Right click: floor square (hold to 'paint')
	Middle click: remove a single square

	WASD Keys: place the player
	F: Fill the area with floor squares
	R: Remove squares
	E: place a door (represented with a '2' character in the .cub file)
	Q: save map (with default colors and texture paths)
```

https://github.com/msKaleb/cub3D_map_editor/assets/116660058/e53b372a-9878-4940-b2f9-9b6ea2b0ce17)https://github.com/msKaleb/cub3D_map_editor/assets/116660058/e53b372a-9878-4940-b2f9-9b6ea2b0ce17



