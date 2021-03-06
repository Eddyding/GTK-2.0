#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。


#include<stdlib.h>
// EXIT_SUCCESS
// EXIT_FAILURE


gint count = 1;

// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{

  //printf("我要退出了\n");
  // sleep(3);
  gtk_main_quit();// 还是需要调用系统的。
// 这里的思路告诉我们，系统的放在最后处理，在此之前，处理我们自己的需求。
// 可以在 on_delete_event 函数中
// 加入其他代码来处理程序开始时遗留的问题(如释放已分配的内存、保存程序配置等),还
// 可以询问用户是否真正退出程序运行。windows系统，点击关闭按钮，询问用户释放退出，
// 不就是这样做的吗！！
}




void
on_button_clicked(GtkWidget *button,gpointer userdata)
{
	g_print("%p",button);
    g_print("你好,这是Hello功能的测试.");
g_print("Hello . This is a test . ");
//g_print("userdata %d\n",(gint)userdata);// userdata传入进来之后，就不再改变。???
g_print("userdata %d\n",(gint)userdata);
g_print("%d\n",count);
count = count + 1 ;
}
int
main(int argc,char *argv[])
{

// EXIT_SUCCESS
// EXIT_FAILURE
    GtkWidget *window;
 GtkWidget *button;
    // 窗口控件指针。
    // GtkWidget是 GTK+2.0控件类型，几乎所有的GTK+2.0控件都用这一类型声明。

    gtk_init(&argc,&argv);
   //初始化命令行参数，这在GTK+2.0程序中是必须的。不管是否用到它。



    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);


  g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(on_delete_event),NULL);




/*

改变窗口外观的几个函数：
设定窗口的标题：
gtk_window_set_title(window,const gchar *title);


设定窗口的默认宽高：
gtk_window_set_default_size(window,int width,int height);

设定窗口的位置：(其实就是x,y坐标)
gtk_window_set_position(window,GtkWindowPosition position);


其中 position 可以取如下值:
GTK_WIN_POS_NONE  不固定
GTK_WIN_POS_CENTER 居中
GTK_WIN_POS_MOUSE  出现在鼠标位置
GTK_WIN_POS_CENTER_ALWAYS  窗口改变尺寸仍居中

GTK_WIN_POS_CENTER_ON_PARENT  居于父窗口的中部
*/






//
    gtk_window_set_title(GTK_WINDOW(window),"Hello 功能实现");
    gtk_window_set_default_size(GTK_WINDOW(window),500,100);
    gtk_window_set_position(GTK_WINDOW(window),
// GTK_WIN_POS_MOUSE
// GTK_WIN_POS_NONE
// GTK_WIN_POS_CENTER_ALWAYS
GTK_WIN_POS_CENTER_ON_PARENT
        );
    //GTK_WIN_POS_CENTER);


gtk_container_set_border_width(GTK_CONTAINER(window),40);

/*
另 一 个 常 用 到 的 与 容 器 相 关 的 函 数 是 gtk_container_set_
border_width。它用来设定容器边框的宽度,格式如例中所示,宽度的单位是像素,可
以根据需要自行设定。如不设定窗口边框的宽度,其默认值是 0

*/
GtkWidget *button2;

button = gtk_button_new_with_label("按下此按钮会在终端上显示一行信息");

//button2 = gtk_button_new_with_label("......");// 没有用，默认一个window只能添加一个控件。

/*

(hello:121866): Gtk-WARNING **: Attempting to add a widget with type GtkButton to a c, but as a GtkBin subclass a GtkWindow can only contain one widget at a time; it already contains a widget of type GtkButton


*/
//g_signal_connect(G_OBJECT(button),"clicked",
//G_CALLBACK(on_button_clicked),(gpointer)count);

g_signal_connect(G_OBJECT(button),"clicked",
G_CALLBACK(on_button_clicked),(gpointer)count);

g_print("main %p",button);


gtk_container_add(GTK_CONTAINER(window),button);
//gtk_container_add(GTK_CONTAINER(window),button2);


gtk_widget_show(button);
//gtk_widget_show(button2);
    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。

    gtk_main();



    return EXIT_SUCCESS;
}

