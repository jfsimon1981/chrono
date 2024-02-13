// Simple console chronometer
// 13/2/24
// BSD-3 License at bottom

#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
using namespace std;

int main(/*int argc, char **argv*/)
{
  unsigned int dtms {0}, dts {0}, dtm {0}, dth {0}, dtd {0};
  const auto start = std::chrono::high_resolution_clock::now();
  while (1) {

  {
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<float, std::milli> elapsed = end - start;
    auto elms {elapsed.count()};
    // elms += (23*3600+59*60+55)*1000; // To start from specific time
    dtms = static_cast<int>(elms) % 1000;
    auto dtst = static_cast<int>(elms) / 1000;
    dts = dtst % (60);
    dtm = (dtst / 60) % 60;
    dth = (dtst / 3600) % 24;
    dtd = dtst / (24*3600);
  }

    std::this_thread::sleep_for(std::chrono::milliseconds(30));

    // TODO
    // Format properly, example (not working)
    // std::fixed << setfill('0') << std::setprecision(2) << setw(3) << std::right
    cout << "dhms.ms " << dtd << "d " \
         << dth << (dtms < 500 ? ":" : " ") << dtm << "\'" \
         << dts << "\"" \
         << "." << dtms \
         << "    \r" << flush;
  }
	return 0;
}




// ************* BSD-3 License *************

/* Copyright 2024 Jean-François Simon, Chrysalide Engineering

  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

      Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
      Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
      Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
