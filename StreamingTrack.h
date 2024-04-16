// Copyright vsatti 2024
#ifndef STREAMINGTRACK_H
#define STREAMINGTRACK_H

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {
 private:
  int num_streams_;
  std::string* genres_;
  int num_genres_;

 public:
  StreamingTrack(const std::string& title = "untitled",
                 const std::string& primary_artist = "unknown",
                 int track_length = 0, int num_artists = 1,
                 const std::string& primary_genre = "pop", int num_streams = 0);
  StreamingTrack(const SongRecording& song,
                 const std::string& primary_genre = "pop", int num_streams = 0);
  StreamingTrack(const StreamingTrack& other);
  ~StreamingTrack();

  int GetStreams() const;
  void SetStreams(int num_streams);
  void AddStreams(int num_streams);

  int GetNumGenres() const;
  std::string GetGenre(int index = 1) const;
  bool IsGenre(const std::string& genre) const;
  void AddGenre(const std::string& genre);
  void RemoveGenre(const std::string& genre);

  StreamingTrack& operator=(const StreamingTrack& other);
};

}  // namespace csce240_programming_assignment_5

#endif  // STREAMINGTRACK_H

