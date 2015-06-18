sudo apt-get -y update
sudo apt-get -y upgrade
sudo rpi-update

sudo apt-get install build-essential cmake pkg-config

sudo apt-get install libjpeg8-dev libtiff4-dev libjasper-dev libpng12-dev

sudo apt-get install libgtk2.0-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt-get install libatlas-base-dev gfortran

mkdir ~/tmp
cd ~/tmp

wget https://bootstrap.pypa.io/get-pip.py
sudo python get-pip.py

sudo pip install virtualenv virtualenvwrapper

echo "
# virtualenv and virtualenvwrapper
export WORKON_HOME=$HOME/.virtualenvs
source /usr/local/bin/virtualenvwrapper.sh
" >> ~/.profile

source ~/.profile
mkvirtualenv cv

sudo apt-get install python2.7-dev

pip install numpy

wget -O opencv-3.0.0.zip http://downloads.sourceforge.net/project/opencvlibrary/opencv-unix/3.0.0/opencv-3.0.0.zip?r=http%3A%2F%2Fsourceforge.net%2Fprojects%2Fopencvlibrary%2F%3Fsource%3Ddirectory&ts=1433709323&use_mirror=heanet
unzip opencv-3.0.0.zip
cd opencv-3.0.0

mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_NEW_PYTHON_SUPPORT=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON ..

make

sudo make install
sudo ldconfig


cd ~/.virtualenvs/cv/lib/python2.7/site-packages/

ln -s /usr/local/lib/python2.7/site-packages/cv2.so cv2.so
ln -s /usr/local/lib/python2.7/site-packages/cv.py cv.py

#workon cv
