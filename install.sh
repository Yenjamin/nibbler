if brew ls --versions sdl2 > /dev/null; then
    echo "The SDL is installed. "
else
    echo "The SDL is not installed. "
    brew install sdl2
fi
if brew ls --versions sfml > /dev/null; then
    echo "The SFML is installed. "
else
    echo "The SFML is not installed. "
    brew install sfml
fi
