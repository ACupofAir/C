//It contains following skills:
//* template
//* operator overloading
//* macro define
#ifndef RECTANGLE_H
#define RECTANGLE_H

template <class T>
class Rectangle {
  private:
    T xLow, yLow, height, width;

  public:
    Rectangle(T xLow_num, T yLow_num, T height_num, T width_num) {
      xLow = xLow_num;
      yLow = yLow_num;
      height = height_num;
      width = width_num;
    } 

    bool operator>(const Rectangle& a);

    //~Rectangle();
}; 

template <class T>
bool Rectangle<T>::operator>(const Rectangle<T>& a) {
  return (height*width > a.height*a.width);
}

#endif

