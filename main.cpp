#include "ComplexPlane.h"
 
int main()
{
 
   //aspect ratio stuff
   double width = VideoMode::getDesktopMode().width;
   double height = VideoMode::getDesktopMode().height;
   double aspectRatio = width/height;
 
   //vid mode obj :0
   VideoMode vm(width, width);
 
 
   // open a windowww
   RenderWindow window(vm, "Mandelbrot Project by Taylor and Senara!", Style::Default);
 
   //complexplane obj
   ComplexPlane complex(aspectRatio);
 
   //text + font obj
   Text messageText;
   Font font;
 
 
   //super cool and never been used before font
   font.loadFromFile("./font/Game Of Squids.ttf");
   messageText.setFont(font);
 
   //array declared 
   VertexArray array;
   array.setPrimitiveType(Points);
   array.resize(width * height);
 
   // set enum status to calc
   windowStatus status= windowStatus::CALCULATING;
 
   //event obj declared
   Event event;
 
 
   while (window.isOpen())
   {
 
       while (window.pollEvent(event)){
 
           if (event.type == Event::Closed)
           {
                window.close();
           }
 
           if (event.type == Event::MouseButtonPressed)
           {
               //coords
               Vector2f coords;
 
               coords = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y), complex.getView());
 
 
               // right click --> zoom out
               if (event.mouseButton.button == Mouse::Right)
               {
                   complex.zoomOut();
                   complex.setCenter(coords);
 
 
               }
               //left click --> zoom in
               if (event.mouseButton.button == Mouse::Left)
               {
                   complex.zoomIn();
                   complex.setCenter(coords);
 
               }
 
               status= windowStatus::CALCULATING;
 
           }
 
           if(event.type == Event::MouseMoved)
           {
               //Find Cursor Coordinate
               Vector2f coords;
 
               coords = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y), complex.getView());
 
               complex.setMouseLocation(coords);
           }
 
       }
 
       if (Keyboard::isKeyPressed(Keyboard::Escape))
       {
           window.close();
       }
   if (status == windowStatus::CALCULATING)
       {
   for (int i=0; i < width; i++)
           {
           for (int j=0; j < height; j++)
               {
                   Uint8 r, g, b = 255;
                   size_t count = 0;
                   Vector2i points{j,i};
                   Vector2f coords;
 
                   array[j+i*width].position={(float)i,(float)j};
                   points = window.mapCoordsToPixel(Vector2f(i, j), complex.getView());
                   coords = Vector2f(points);
 
                   count= complex.countIterations(coords);
 
                   complex.iterationsToRGB(count,r,g,b);
 
                   array[j+i*width].color={r,g,b};
 
 
               }
           }
 
           status = windowStatus::DISPLAYING;
           complex.loadText(messageText);
       }
 
 
       window.clear();
 
       window.draw(array);
 
       window.draw(messageText);
      
       window.display();
 
 
   }
 
   return 0;
}
 
 

