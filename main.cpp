#include "building.h"

#define GLFW_DLL
#include <glfw.h>
#include <glut.h>
#include <stdlib.h>
#include<stdio.h>
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#pragma comment(lib,"glfw.lib")
#pragma comment(lib,"glfwdll.lib")
#pragma comment(lib, "opengl32.lib")
void initScene(int w,int h)
{
    // ������Ӱƽ��
    glShadeModel( GL_SMOOTH );
    // ��ɫ����
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    // ������Ȼ���
    glClearDepth( 1.0 );
    // ������Ȳ���
    glEnable( GL_DEPTH_TEST );
    // ������Ȳ��Ե�����
    glDepthFunc( GL_LEQUAL );
    // ����ϵͳ��͸�ӽ�������
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}
//����������еĻ�ͼ����
void  drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                                   // Reset The View
    glTranslatef(0.0f  ,0.0f  ,-5.0f  );
    //����һ��������
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-1.0f  , -1.0f  ,  1.0f  );
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f  , -1.0f  ,  1.0f  );
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f  ,  1.0f  ,  1.0f  );
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f(-1.0f  ,  1.0f  ,  1.0f  );
    glEnd();
    // ����������
    glfwSwapBuffers();
}
//���ô��ڴ�С��Ļص�����
void GLFWCALL resizeGL(int width, int height )
{
    // ��ֹ���ڴ�С��Ϊ0
    if ( height == 0 )
    {
        height = 1;
    }
    // ���õ�ǰ���ӿ�
    glViewport( 0, 0, (GLint)width, (GLint)height );
    // ѡ��ͶӰ����
    glMatrixMode( GL_PROJECTION );
    // ����ͶӰ����
    glLoadIdentity();
    // �����ӿڵĴ�С
    gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
    // ѡ��ģ�͹۲����
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

int main( void )
{
    //��¼��������״̬
    int running = GL_TRUE;
    //��ʼ�� GLFW
    if( !glfwInit() )
    {
        exit( EXIT_FAILURE );
    } 
    // ����һ��OpenGL ����
    if( !glfwOpenWindow( WINDOW_WIDTH,WINDOW_HEIGHT,6,6,6,0,32,0,GLFW_WINDOW) )
    {
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    //��ʼ��OpenGL����
    initScene(WINDOW_WIDTH, WINDOW_HEIGHT);
    //���ô��ڴ�С�����仯ʱ�Ļص�����
    glfwSetWindowSizeCallback(resizeGL);
    //��ѭ��
    while( running )
    {
        // OpenGL rendering goes here...
        glClear( GL_COLOR_BUFFER_BIT );
        // ������ESC����ʱ�򴥷�
        running = !glfwGetKey( GLFW_KEY_ESC ) &&glfwGetWindowParam( GLFW_OPENED );
	drawScene();
        //��ʱ0.05��
	glfwSleep(0.05 );
    }
    glfwTerminate();
    //�˳�����
    exit( EXIT_SUCCESS );
}