#include<iostream> 
#include<glad/glad.h> 
#include<GLFW/glfw3.h> 

using namespace std;

int main()
{
	// Initialize GLFW
	glfwInit(); 
	// tell GLFW what version we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 

	//tell GLFW we are using the core profile which is the modern functions 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	// Create the window object with an 800 by 800 frame and naming it opengl setup 
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGl-Setup", NULL, NULL);  
	// error Check that terminates window if it can't open
	if (window == NULL) 
	{
		cout << "Failed to create GLFW window" << endl; 

		glfwTerminate(); 
		return -1; 
	}
	//Introdue the window into the current context
	glfwMakeContextCurrent(window);  
	
	//load glad to configure open gl
	gladLoadGL();  

	//specify openGL viewport
	glViewport(0, 0, 800, 800); 

	 //specify background  color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//clean back buffer and assign the new color
	glClear(GL_COLOR_BUFFER_BIT); 
	//swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	
	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		// handle all glfw events
		glfwPollEvents();
	}

	
	//delete the window before ending the program
	glfwDestroyWindow(window); 
	  
	//terminate GLFW
	glfwTerminate();
	return 0;
}