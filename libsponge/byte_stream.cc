#include "byte_stream.hh"
#include <cstddef>
#include <numeric>

// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

ByteStream::ByteStream(const size_t capacity) { DUMMY_CODE(capacity); }

size_t ByteStream::write(const string &data) {
    DUMMY_CODE(data);
    if (input_end == false ){
        return false;
    }
    size_t remain = capacity - buf.size();     
    size_t write_count = std::min(data.size(),remain);
    write_bytes += write_count;
    buf.insert(buf.end(),data.begin(),data.begin()+write_count);

    return write_count;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
    DUMMY_CODE(len);
    size_t read_count = std::min(len,buf.size());
    return std::string(buf.begin(),buf.begin() + read_count);
    
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
    
    DUMMY_CODE(len); 

    size_t pop_count = std::min(len, buf.size());
    read_bytes += pop_count;
    buf.erase(buf.begin(), buf.begin() + pop_count);
}



//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
    DUMMY_CODE(len);
    //as a merge of peek_output and pop_output
    return {};
}

void ByteStream::end_input() {input_end = true;}

bool ByteStream::input_ended() const { return input_end; }

size_t ByteStream::buffer_size() const { return buf.size(); }

bool ByteStream::buffer_empty() const { return buf.empty(); }

bool ByteStream::eof() const { return buffer_empty() && input_end; }

size_t ByteStream::bytes_written() const { return write_bytes; }

size_t ByteStream::bytes_read() const { return read_bytes; }

size_t ByteStream::remaining_capacity() const { return capacity - buf.size(); }
