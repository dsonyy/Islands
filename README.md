# Islands

The "Islands" project is a really basic game engine built from scratch. I use that as a sandbox for lerning and experiments. Keep in mind that the code quality may not be amazing.

## Installation

It has never planned to make this software cross-platform, so only Windows is supported.
The project was created using Visual Studio 2017.

### What do you need:
- Windows,
- Visual Studio (project was created on 2017 edition),
- SFML (version 2.4.2 (32bit) for Visual C++ is recommended)

### Download Links:
- SFML: https://www.sfml-dev.org/download/sfml/2.4.2/
- Visual Studio: https://www.visualstudio.com/

### SFML Installation
If you just download SFML:
1. Copy unpacked SFML archive to the main project directory (aside LISENSE, README.md etc).
2. Make sure that SFML folder is called "SFML".

If you have SFML somewhere in your computer:
1. Open Islands/Islands/DebugProperties.props to change Debug mode paths.
2. Change "AdditionalIncludeDirectories" to your own SFML "include" directory path.
3. Change "AdditionalDependencies" to your own paths of:
- "sfml-system-d.lib", 
- "sfml-window-d.lib",
- "sfml-graphics-d.lib".

4. Open Islands/Islands/ReleaseProperties.props to change Release mode paths.
5. Change "AdditionalIncludeDirectories" to your own SFML "include" directory path.
6. Change "AdditionalDependencies" to your own paths of:
- "sfml-system.lib", 
- "sfml-window.lib",
- "sfml-graphics.lib".

If you think about static linking, you have to do it in your own. More info there: https://www.sfml-dev.org/tutorials/2.4/start-vc.php 

### Compiling
If you successfully install SFML, open .sln file and build project in Debug or Release mode.


