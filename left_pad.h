/*
 * Copyright (c) 2016, Nelson Castillo
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of Nelson nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Nelson BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LEFT_PAD_H_
#define LEFT_PAD_H_

#include <string>

namespace not_kik {

// Prepend desired character enough times to make it have the desired length.
// If str is "foo",  desired_length is 5 and ch is ' ', the resould will be
// "  foo".
std::string LeftPad(const std::string &str, int desired_length, char ch);

// Same as previous LeftPad but it modifies the original string. This version
// might be more efficient for older C++ versions.
void LeftPad(int desired_length, char ch, std::string *str);

// Object oriented interface for LeftPad.
class LeftPadder {
 public:
  // Create a LeftPadder instance specialized for a character.
  // If ommited, the character is set to ' '.
  explicit LeftPadder(char ch = ' ') : ch_(ch) {}

  // Pad str with the desired length.
  std::string Pad(const std::string str, int desired_length) {
    return LeftPad(str, desired_length, ch_);
  }

  // Pad str with the desired length. In-place version.
  void Pad(int desired_length, std::string *str) {
    return LeftPad(desired_length, ch_, str);
  }

 private:
  char ch_;
};

}  // namespace not_kik

#endif  // LEFT_PAD_H_
