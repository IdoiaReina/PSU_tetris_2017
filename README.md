# PSU_tetris_2017
Epitech's Tetris from March 2018<br />
Clone of tetris game in a UNIX terminal with ncurses library.

## Compile the project

    $ git clone https://github.com/IdoiaReina/PSU_tetris_2017.git
    $ cd tetris
    $ make
    $ ./tetris

## Commands program

    Usage: ./tetris [options]
    Options:
    --help               Display this help
    -l --level={num}     Start Tetris at level num
    -kl --key-left={K}   Move tetrimino on LEFT with key K
    -kr --key-right={K}  Move tetrimino on RIGHT with key K
    -kt --key-turn={K}   Turn tetrimino with key K
    -kd --key-drop={K}   Set default DROP on key K
    -kq --key-quit={K}   Quit program when press key K
    -kp --key-pause={K}  Pause and restart game when press key K
    --map-size={row,col} Set game size at row, col
    -w --without-next    Hide next tetrimino
    -d --debug           Debug mode

## Customs shapes

You can custom the shapes of tetriminos in the folder "tetriminos". <br />
You can see several examples in the files. <br />

#

Dev by [Idoia Reinares](https://github.com/IdoiaReina "Idoia's profile") and [Leo Couffinhal](https://github.com/Suissehide "Leo's profile")
