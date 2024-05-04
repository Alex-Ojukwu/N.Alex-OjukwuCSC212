#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	//Initialize glfw
	glfwInit();
	//Tell GLFW what version of OpenGL we are using
	//In This case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//tell    glfw we are using core profile
	//so that we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creat a GLFWwindow object of 800 by 800 pixels, namin git  OpenGL
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);

	//error check if window fails to create
	if (window == NULL)
	{
		std::cout << "Failed  to create GLFW window " << std::endl;
        glfwTerminate();
		return -1;
	}
	//introduce the window into the current context
	glfwMakeContextCurrent(window);
	//load GLAD so it configures OpenGL
	gladLoadGL();

	//specify the viewport of OpenGL in the window
	//in this case the viewport goes from x= 0,y=0 , to x=800 , y=800
	glViewport(0, 0, 800, 800); 

	//specify the color of background, the last place 1.0f bieng the opacity of the color( 0.0f is transparent)
	glClearColor(0.07f, 0.27f, 0.27f, 1.0f);
	//clean the back buffer and assign a new colour to it
	glClear(GL_COLOR_BUFFER_BIT);
	//swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	// main while loop  so the window stays and not terminate after creation
	while (!glfwWindowShouldClose(window))
	{
		//take care of GLFW events
		glfwPollEvents();
	}

    //delete window before ending the program
	glfwDestroyWindow(window);
	//Terminate GLFW before ending the program
	glfwTerminate(); 
	return 0;
}