LEARN OPENGL

Bug and Progress DAY 1:

- Fix the bug and explore more how to add new header on c++/mingw64
- Debug and see the undefined in checkversion code

Progress DAY 2:

- Clangd not config yet so thats why the file header is not found
- Install clang++, study about proper compiling in c++ using g++ or clang++.

PROGRESS DAY 3:

- Still error

PROGRESS DAY 4:

- FUCK I DID IT, SO BASICLY WE ADD THE CMakeFiles FOR EASIER COSTUME AND COMPILE, SO AND THE END WE USE G++ AND CLANGD FOR THIS PROJECT.
- FIRST: cmake -S . -B build -G "MinGW Makefiles"
- USE cmake --build build
- NEXT build\\app.exe

# NEXT LERN HOW TO INSERTING FILE C++ OR OVEN FUNCTIONS AND SO ON IN THE main.cpp, SO WE CAN COMPILE IT AT ONE

# LERN OPENGL CONTINUE THE learnopengl.com

PROGRESS DAY 5:

- learning how to add new library like glad.
- wondering, when I change/update the cmakelist, did I need to remove build and remake it after that doing cmake build?
- we didnt learn about linked among c++ file into main.cpp

PROGRESS DAY 6:

- leaarning how to render a "window" using opengl
- learning how to make void functions and insert it on rendering looping
- learn a little but about color
- display a blank windows with some color and close it using "ESC"

PROGRESS DAY 7:

- hello triangle
- learn to create hello triangle but still not really understand bout that.
- need to recheck again and learn deeply
- for now its not showing something even after add the shaders like vertex, and fragment
- I thinks its about linked or something we need to check again on the docs, see ya.

PROGRESS DAY-8:

- we learn a lot about vertices, and VAO in here.
- so the result we already can displaying triangle.
- need to learn more about how it working, and randering, cuz its include GPU, rendeing, linked list, and pointer fields about this one.
- try to costume the output and make it more.
- solve the exercises after that

PROGRESS DAY-9:

- Lean a little bit about tringle and how to displaying more then t.
- Still struggle about how its works and how to change the space output between each others triangles.

PROGRESS DAY-10:

- try to figure out what happened in vertices.
- I thinks we did the first exercises.

PROGRESS DAY-11:

- see the solutions about 1 questions.
- refactoring a bit bout the whole code (structure)

PROGRESS DAY-12:

- fix shader fragment add log missing log info
- questions number 2 is done I thinks need more improved in future IG, ah and check the solutions next, goota go to sleep bye.

PROGRESS DAY-13:

- I thinks I get the way how to solve the Q3, lets see at 10/11PM
- Questions Number 3 is done, and done for uploading on GitHub also

PROGRESS DAY-14:

next learn about shaders things (continue chapters)

PROGRESS DAY-15:
- learn about vertec shader and frament shader in detail, its contain in and out and also we already implement using the same type in shader and coloring but we didnt exe it yet
- next learn about this things try to rendering it and move into UNIFROM things, I gotta go so see ya 


PROGRESS DAY-16:
- fix and implement full in and out, figure out whats the bug things before and fix it.
- next gotta learn bout uniforms on shaders things, gotta sleep now so see ya.

PROGRESS DAY-17:
- learning about unifrom and how to used it to update color value each frame, for now we already figure out bout green color only for the tringle.
- now the full triangle is already goin change or update ech frame, but what If I try to update color for each vertex? Lets figure it out next time, gotta sleep now cuz I just arrived home, see ya.

PROGRESS DAY-18:
- continue to render 3 dif color triangle using more vertices, shader and fragment. So when we change the shader-fragment source we must change also aout the VAO, and to make it clear its called "FRAGMENT INTERPOLATION"
- Based on these positions, it interpolates all the fragment shader's input variables. Say for example we have a line where the upper point has a green color and the lower point a blue color. If the fragment shader is run at a fragment that resides around a position at 70% of the line, its resulting color input attribute would then be a linear combination of green and blue; to be more precise: 30% blue and 70% green.
- This is exactly what happened at the triangle. We have 3 vertices and thus 3 colors, and judging from the triangle's pixels it probably contains around 50000 fragments, where the fragment shader interpolated the colors among those pixels. 

PROGRESS DAY-19
- refactoring the previouse code, learn more about how this working, next try to figure it out all and do some exercises.

PROGRSS DAY-20
- So we continue it again, now I already create a profer header file but still didnt know how to used it on main cpp. Next figure out this one. 
