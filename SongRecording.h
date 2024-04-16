// Copyright vsatti 2024
#ifndef SONGRECORDING_H
#define SONGRECORDING_H

#include <iostream>
#include <string>

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
  std::string title_;
  std::string* artists_;
  int num_artists_;
  int track_length_;

 public:
  SongRecording(const std::string& title = "untitled",
                const std::string& primary_artist = "unknown",
                int track_length = 0, int num_artists = 1);
  SongRecording(const SongRecording& other);
  ~SongRecording();

  std::string GetTitle() const;
  void SetTitle(const std::string& title);

  int GetNumArtists() const;
  void SetNumArtists(int num_artists);

  void SetArtist(const std::string& artist, int index = 1);
  std::string GetArtist(int index = 1) const;

  int GetTrackLength() const;
  void SetTrackLength(int track_length);

  SongRecording& operator=(const SongRecording& other);
};

}  // namespace csce240_programming_assignment_5

#endif  // SONGRECORDING_H

