// Copyright vsatti 2024
#include "StreamingTrack.h"

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(const std::string& title,
                               const std::string& primary_artist,
                               int track_length, int num_artists,
                               const std::string& primary_genre, int num_streams)
    : SongRecording(title, primary_artist, track_length, num_artists),
      num_streams_(num_streams), num_genres_(1) {
  genres_ = new std::string[num_genres_];
  genres_[0] = primary_genre;
}

StreamingTrack::StreamingTrack(const SongRecording& song,
                               const std::string& primary_genre, int num_streams)
    : SongRecording(song), num_streams_(num_streams), num_genres_(1) {
  genres_ = new std::string[num_genres_];
  genres_[0] = primary_genre;
}

StreamingTrack::StreamingTrack(const StreamingTrack& other)
    : SongRecording(other), num_streams_(other.num_streams_),
      num_genres_(other.num_genres_) {
  genres_ = new std::string[num_genres_];
  for (int i = 0; i < num_genres_; ++i) {
    genres_[i] = other.genres_[i];
  }
}

StreamingTrack::~StreamingTrack() { delete[] genres_; }

int StreamingTrack::GetStreams() const { return num_streams_; }

void StreamingTrack::SetStreams(int num_streams) {
  if (num_streams >= 0) {
    num_streams_ = num_streams;
  }
}

void StreamingTrack::AddStreams(int num_streams) {
  if (num_streams >= 0) {
    num_streams_ += num_streams;
  }
}

int StreamingTrack::GetNumGenres() const { return num_genres_; }

std::string StreamingTrack::GetGenre(int index) const {
  if (index >= 1 && index <= num_genres_) {
    return genres_[index - 1];
  } else {
    return "out of bounds";
  }
}

bool StreamingTrack::IsGenre(const std::string& genre) const {
  for (int i = 0; i < num_genres_; ++i) {
    if (genres_[i] == genre) {
      return true;
    }
  }
  return false;
}

void StreamingTrack::AddGenre(const std::string& genre) {
  if (!IsGenre(genre)) {
    std::string* new_genres = new std::string[num_genres_ + 1];
    for (int i = 0; i < num_genres_; ++i) {
      new_genres[i] = genres_[i];
    }
    new_genres[num_genres_] = genre;
    delete[] genres_;
    genres_ = new_genres;
    num_genres_++;
  }
}

void StreamingTrack::RemoveGenre(const std::string& genre) {
  if (IsGenre(genre)) {
    std::string* new_genres = new std::string[num_genres_ - 1];
    int new_index = 0;
    for (int i = 0; i < num_genres_; ++i) {
      if (genres_[i] != genre) {
        new_genres[new_index++] = genres_[i];
      }
    }
    delete[] genres_;
    genres_ = new_genres;
    num_genres_--;
  }
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other) {
  if (this != &other) {
    SongRecording::operator=(other);
    num_streams_ = other.num_streams_;
    num_genres_ = other.num_genres_;
    delete[] genres_;
    genres_ = new std::string[num_genres_];
    for (int i = 0; i < num_genres_; ++i) {
      genres_[i] = other.genres_[i];
    }
  }
  return *this;
}

}  // namespace csce240_programming_assignment_5

