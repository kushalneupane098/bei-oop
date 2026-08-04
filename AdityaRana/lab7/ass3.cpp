#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class MediaFile {
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;
    virtual ~MediaFile() {
        cout << "MediaFile Destructor" << endl;
    }
};

class AudioFile : public MediaFile {
private:
    int duration;
    int bitrate;
public:
    AudioFile(int dur, int br) : duration(dur), bitrate(br) {}
    ~AudioFile() override { cout << "AudioFile Destructor" << endl; }
    
    void play() override { cout << "Playing Audio" << endl; }
    string getInfo() override { return "Audio Duration: " + to_string(duration); }
    int getBitrate() { return bitrate; }
};

class VideoFile : public MediaFile {
private:
    int duration;
    string resolution;
public:
    VideoFile(int dur, string res) : duration(dur), resolution(res) {}
    ~VideoFile() override { cout << "VideoFile Destructor" << endl; }
    
    void play() override { cout << "Playing Video" << endl; }
    string getInfo() override { return "Video Duration: " + to_string(duration); }
    string getResolution() { return resolution; }
};

class ImageFile : public MediaFile {
private:
    int width;
    int height;
public:
    ImageFile(int w, int h) : width(w), height(h) {}
    ~ImageFile() override { cout << "ImageFile Destructor" << endl; }
    
    void play() override { cout << "Displaying Image" << endl; }
    string getInfo() override { return "Image Dimensions: " + to_string(width) + "x" + to_string(height); }
};

int main() {
    vector<MediaFile*> playlist;
    playlist.push_back(new AudioFile(240, 320));
    playlist.push_back(new VideoFile(7200, "1080p"));
    playlist.push_back(new ImageFile(1920, 1080));

    for (MediaFile* file : playlist) {
        cout << typeid(*file).name() << endl;
        file->play();
        cout << file->getInfo() << endl;

        VideoFile* vid = dynamic_cast<VideoFile*>(file);
        if (vid != nullptr) {
            cout << "Resolution: " << vid->getResolution() << endl;
        }

        AudioFile* aud = dynamic_cast<AudioFile*>(file);
        if (aud != nullptr) {
            cout << "Bitrate: " << aud->getBitrate() << endl;
        }
    }

    for (MediaFile* file : playlist) {
        delete file;
    }
    playlist.clear();

    return 0;
}