#include <GLLog.h>



bool restart_gl_log () {
  FILE* file = fopen (GL_LOG_FILE, "w+");
  if (!file) {
    fprintf (stderr, "ERROR: could not open %s log file for writing\n", GL_LOG_FILE);
    return false;
  }
  time_t now = time (NULL);
  char* date = ctime (&now);
  fprintf (file, "%s log. local time %s\n", GL_LOG_FILE, date);
  fclose (file);
  return true;
}

bool gl_log (const char* message, const char* filename, int line) {
  FILE* file = fopen (GL_LOG_FILE, "a+");
  if (!file) {
    fprintf (stderr, "ERROR: could not open %s for writing\n", GL_LOG_FILE);
    return false;
  }
  fprintf (file, "%s:%i %s\n", filename, line, message);
  fclose (file);
  return true;
}

bool printShaderInfoLog(GLuint obj)
{
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;

	glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
		free(infoLog);
		return false;
	}
	return true;
}
bool printProgramInfoLog(GLuint obj)
{
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;

	glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
		free(infoLog);
	return false;
	}
	return true;
}

void log_gl_params () {
	GLenum params[] = {
		GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
		GL_MAX_CUBE_MAP_TEXTURE_SIZE,
		GL_MAX_DRAW_BUFFERS,
		GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
		GL_MAX_TEXTURE_IMAGE_UNITS,
		GL_MAX_TEXTURE_SIZE,
		GL_MAX_VARYING_FLOATS,
		GL_MAX_VERTEX_ATTRIBS,
		GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
		GL_MAX_VERTEX_UNIFORM_COMPONENTS,
		GL_MAX_VIEWPORT_DIMS,
		GL_STEREO,
	};
	const char* names[] = {
		"GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
		"GL_MAX_CUBE_MAP_TEXTURE_SIZE",
		"GL_MAX_DRAW_BUFFERS",
		"GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
		"GL_MAX_TEXTURE_IMAGE_UNITS",
		"GL_MAX_TEXTURE_SIZE",
		"GL_MAX_VARYING_FLOATS",
		"GL_MAX_VERTEX_ATTRIBS",
		"GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
		"GL_MAX_VERTEX_UNIFORM_COMPONENTS",
		"GL_MAX_VIEWPORT_DIMS",
		"GL_STEREO",
	};
	gl_log ("GL Context Params:", __FILE__, __LINE__);
	char msg[256];
	// integers - only works if the order is 0-10 integer return types
	for (int i = 0; i < 10; i++) {
		int v = 0;
		glGetIntegerv (params[i], &v);
		sprintf (msg, "%s %i", names[i], v);
		gl_log (msg, __FILE__, __LINE__);
	}
	// others
	int v[2];
	v[0] = v[1] = 0;
	glGetIntegerv (params[10], v);
	sprintf (msg, "%s %i %i", names[10], v[0], v[1]);
	gl_log (msg, __FILE__, __LINE__);
	unsigned char s = 0;
	glGetBooleanv (params[11], &s);
	sprintf (msg, "%s %i", names[11], (unsigned int)s);
	gl_log (msg, __FILE__, __LINE__);
	gl_log ("-----------------------------", __FILE__, __LINE__);
}
