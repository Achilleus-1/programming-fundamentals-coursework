# Development

Use Python 3.12, a JDK and GCC. `python tools/check_repository.py` compiles the
three C programs, calorie tracker, cyclone exercise and two drawing programs
as separate targets. Each exercise is independent; run from its own directory.

The original DrawingPanel helper was unavailable. `support/DrawingPanel.java`
is a new small Swing compatibility helper for the methods these exercises use.
It is maintenance code under the scoped MIT license, not the original supplied
course library. Compile it together with Helix.java or ScreenSaver.java, then
run the resulting class on a desktop with a display. CI checks compilation only.

`java/debugging-exercises` preserves intentionally incomplete/broken debugging
samples. They are archival examples and are excluded from supported build targets.
Any absent original input should be obtained from an authorized course source;
do not commit assignment instructions or personal submissions.
