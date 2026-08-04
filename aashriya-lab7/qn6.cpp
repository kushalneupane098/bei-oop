#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class MediaFile {
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;

    virtual ~MediaFile() {
        cout << "MediaFile Destructor Called" << endl;
    }
};

class AudioFile : public MediaFile {
    int duration;
    int bitrate;

public:
    AudioFile(int d, int b)
        : duration(d), bitrate(b) {}

    void play() override {
        cout << "Playing Audio File..." << endl;
    }

    string getInfo() override {
        return "Audio: Duration = " + to_string(duration)
             + " sec, Bitrate = "
             + to_string(bitrate) + " kbps";
    }

    int getBitrate() {
        return bitrate;
    }

    ~AudioFile() {
        cout << "AudioFile Destructor Called" << endl;
    }
};

class VideoFile : public MediaFile {
    int duration;
    string resolution;

public:
    VideoFile(int d, string r)
        : duration(d), resolution(r) {}

    void play() override {
        cout << "Playing Video File..." << endl;
    }

    string getInfo() override {
        return "Video: Duration = " + to_string(duration)
             + " sec, Resolution = " + resolution;
    }

    string getResolution() {
        return resolution;
    }

    ~VideoFile() {
        cout << "VideoFile Destructor Called" << endl;
    }
};

class ImageFile : public MediaFile {
    int width, height;

public:
    ImageFile(int w, int h)
        : width(w), height(h) {}

    void play() override {
        cout << "Displaying Image..." << endl;
    }

    string getInfo() override {
        return "Image: Width = "
             + to_string(width)
             + ", Height = "
             + to_string(height);
    }

    ~ImageFile() {
        cout << "ImageFile Destructor Called" << endl;
    }
};

int main() {
    vector<MediaFile*> files;

    files.push_back(new AudioFile(180, 320));
    files.push_back(new VideoFile(600, "1920x1080"));
    files.push_back(new ImageFile(1024, 768));

    for (MediaFile* ptr : files) {

       
        cout << "\nRuntime Type: "
             << typeid(*ptr).name() << endl;

        ptr->play();
        cout << ptr->getInfo() << endl;

        VideoFile* vptr = dynamic_cast<VideoFile*>(ptr);
        if (vptr) {
            cout << "Video Resolution: "
                 << vptr->getResolution()
                 << endl;
        }

       
        AudioFile* aptr = dynamic_cast<AudioFile*>(ptr);
        if (aptr) {
            cout << "Audio Bitrate: "
                 << aptr->getBitrate()
                 << " kbps" << endl;
        }
    }

    cout << "\nDeleting Objects...\n";

    for (MediaFile* ptr : files) {
        delete ptr;
    }

    files.clear();

    return 0;
}

