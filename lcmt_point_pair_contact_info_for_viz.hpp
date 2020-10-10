/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __lcmt_point_pair_contact_info_for_viz_hpp__
#define __lcmt_point_pair_contact_info_for_viz_hpp__

#include <lcm/lcm_coretypes.h>

#include <string>


class lcmt_point_pair_contact_info_for_viz
{
    public:
        /**
         * TODO(edrumwri) Consider removing this data which is already present in the
         * structure in which this message is stored (lcmt_contact_results_for_viz).
         * In microseconds
         */
        int64_t    timestamp;

        /// Names of the colliding bodies
        std::string body1_name;

        std::string body2_name;

        /// These are all expressed in the world frame.
        double     contact_point[3];

        double     contact_force[3];

        double     normal[3];

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "lcmt_point_pair_contact_info_for_viz"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int lcmt_point_pair_contact_info_for_viz::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int lcmt_point_pair_contact_info_for_viz::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int lcmt_point_pair_contact_info_for_viz::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t lcmt_point_pair_contact_info_for_viz::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* lcmt_point_pair_contact_info_for_viz::getTypeName()
{
    return "lcmt_point_pair_contact_info_for_viz";
}

int lcmt_point_pair_contact_info_for_viz::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->timestamp, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* body1_name_cstr = const_cast<char*>(this->body1_name.c_str());
    tlen = __string_encode_array(
        buf, offset + pos, maxlen - pos, &body1_name_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* body2_name_cstr = const_cast<char*>(this->body2_name.c_str());
    tlen = __string_encode_array(
        buf, offset + pos, maxlen - pos, &body2_name_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->contact_point[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->contact_force[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->normal[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int lcmt_point_pair_contact_info_for_viz::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->timestamp, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    int32_t __body1_name_len__;
    tlen = __int32_t_decode_array(
        buf, offset + pos, maxlen - pos, &__body1_name_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__body1_name_len__ > maxlen - pos) return -1;
    this->body1_name.assign(
        static_cast<const char*>(buf) + offset + pos, __body1_name_len__ - 1);
    pos += __body1_name_len__;

    int32_t __body2_name_len__;
    tlen = __int32_t_decode_array(
        buf, offset + pos, maxlen - pos, &__body2_name_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__body2_name_len__ > maxlen - pos) return -1;
    this->body2_name.assign(
        static_cast<const char*>(buf) + offset + pos, __body2_name_len__ - 1);
    pos += __body2_name_len__;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->contact_point[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->contact_force[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->normal[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int lcmt_point_pair_contact_info_for_viz::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += this->body1_name.size() + 4 + 1;
    enc_size += this->body2_name.size() + 4 + 1;
    enc_size += __double_encoded_array_size(NULL, 3);
    enc_size += __double_encoded_array_size(NULL, 3);
    enc_size += __double_encoded_array_size(NULL, 3);
    return enc_size;
}

uint64_t lcmt_point_pair_contact_info_for_viz::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x8927252e061770f4LL;
    return (hash<<1) + ((hash>>63)&1);
}

#endif
