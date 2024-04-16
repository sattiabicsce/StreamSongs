// Copyright vsatti 2024
#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(const std::string& title,
                             const std::string& primary_artist,
                             int track_length, int num_artists)
    : title_(title), num_artists_(num_artists) {
  if (track_length >= 0) {
    track_length_ = track_length;
  } else {
    track_length_ = 0;  // Set track length to zero for negative values
  }

  if (num_artists_ <= 0) {
    num_artists_ = 1;  // Ensure at least one artist
  }

  artists_ = new std::string[num_artists_];
  artists_[0] = primary_artist.empty() ? "unknown" : primary_artist;
}

SongRecording::SongRecording(const SongRecording& other)
    : title_(other.title_), num_artists_(other.num_artists_),
      track_length_(other.track_length_) {
  artists_ = new std::string[num_artists_];
  for (int i = 0; i < num_artists_; ++i) {
    artists_[i] = other.artists_[i];
  }
}

SongRecording::~SongRecording() { delete[] artists_; }

std::string SongRecording::GetTitle() const { return title_; }

void SongRecording::SetTitle(const std::string& title) {
  if (!title.empty()) {
    title_ = title;
  }
}

int SongRecording::GetNumArtists() const { return num_artists_; }

void SongRecording::SetNumArtists(int num_artists) {
  if (num_artists <= 0) {
    return;  // Do nothing for invalid input
  }
  std::string* new_artists = new std::string[num_artists];
  for (int i = 0; i < std::min(num_artists, num_artists_); ++i) {
    new_artists[i] = artists_[i];
  }
  delete[] artists_;
  artists_ = new_artists;
  num_artists_ = num_artists;
}

void SongRecording::SetArtist(const std::string& artist, int index) {
  if (index >= 1 && index <= num_artists_ && !artist.empty()) {
    artists_[index - 1] = artist;
  }
}

std::string SongRecording::GetArtist(int index) const {
  if (index >= 1 && index <= num_artists_) {
    return artists_[index - 1];
  } else {
    return "out of bounds";
  }
}

int SongRecording::GetTrackLength() const { return track_length_; }

void SongRecording::SetTrackLength(int track_length) {
  if (track_length >= 0) {
    track_length_ = track_length;
  }
}

SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    title_ = other.title_;
    delete[] artists_;
    artists_ = new std::string[other.num_artists_];
    for (int i = 0; i < other.num_artists_; ++i) {
      artists_[i] = other.artists_[i];
    }
    num_artists_ = other.num_artists_;
    track_length_ = other.track_length_;
  }
  return *this;
}

}  // namespace csce240_programming_assignment_5

