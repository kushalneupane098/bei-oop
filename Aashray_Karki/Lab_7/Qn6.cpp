/*
Assignment 3:
Combine virtual functions, abstract classes, virtual destructors, and RTTI
using MediaFile, AudioFile, VideoFile, and ImageFile.
*/

#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

class MediaFile {
public:
    virtual void play() const = 0;
    virtual string getInfo() const = 0;

    virtual ~MediaFile() {
        cout << "MediaFile destructor called" << endl;
    }
};

class AudioFile : public MediaFile {
private:
    int duration;
    int bitrate;

public:
    AudioFile(int d, int b) {
        duration = d;
        bitrate = b;
    }

    void play() const override {
        cout << "Playing audio file" << endl;
    }

    string getInfo() const override {
        return "Audio Duration: " + to_string(duration) + " seconds";
    }

    int getBitrate() const {
        return bitrate;
    }

    ~AudioFile() override {
        cout << "AudioFile destructor called" << endl;
    }
};

class VideoFile : public MediaFile {
private:
    int duration;
    string resolution;

public:
    VideoFile(int d, string r) {
        duration = d;
        resolution = r;
    }

    void play() const override {
        cout << "Playing video file" << endl;
    }

    string getInfo() const override {
        return "Video Duration: " + to_string(duration) + " seconds";
    }

    string getResolution() const {
        return resolution;
    }

    ~VideoFile() override {
        cout << "VideoFile destructor called" << endl;
    }
};

class ImageFile : public MediaFile {
private:
    int width;
    int height;

public:
    ImageFile(int w, int h) {
        width = w;
        height = h;
    }

    void play() const override {
        cout << "Displaying image file" << endl;
    }

    string getInfo() const override {
        return "Image Size: " + to_string(width) + " x " + to_string(height);
    }

    ~ImageFile() override {
        cout << "ImageFile destructor called" << endl;
    }
};

int main() {
    vector<MediaFile*> files;

    files.push_back(new AudioFile(180, 320));
    files.push_back(new VideoFile(600, "1920x1080"));
    files.push_back(new ImageFile(800, 600));

    for (MediaFile *ptr : files) {
        cout << "\nRuntime Type: " << typeid(*ptr).name() << endl;
        ptr->play();
        cout << ptr->getInfo() << endl;

        VideoFile *v = dynamic_cast<VideoFile*>(ptr);
        if (v != NULL)
            cout << "Resolution: " << v->getResolution() << endl;

        AudioFile *a = dynamic_cast<AudioFile*>(ptr);
        if (a != NULL)
            cout << "Bitrate: " << a->getBitrate() << " kbps" << endl;
    }

    cout << "\nDeleting objects:" << endl;
    for (MediaFile *ptr : files) {
        delete ptr;
    }

    files.clear();

    return 0;
}