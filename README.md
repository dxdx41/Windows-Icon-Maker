## Windows Icon Maker
A program that takes image file path as command line argument and creates an icon with multiple sizes.
- Exe needs to be in the same directory as the image, unless you add it to path I think.
- Requires [ffmpeg](https://www.ffmpeg.org/) and [imagemagic](https://imagemagick.org/script/download.php) to be installed and added to path.
- It uses the system() function to call ffmpeg and magick commands so maybe it will work on other os.