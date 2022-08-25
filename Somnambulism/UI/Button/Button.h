//
//  Button.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/23.
//

#ifndef Button_h
#define Button_h

typedef struct{
    Texture   tex;
    Rectangle rect;
    void(*func[6])(void);
    /*
    typedef enum {
     MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
     MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
     MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
     MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
     MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
     MOUSE_BUTTON_FORWARD = 5,       // Mouse button fordward (advanced mouse device)
     MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
    } MouseButton;
     */
} UIButton;

#endif /* Button_h */
