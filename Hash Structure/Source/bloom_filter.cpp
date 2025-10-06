#include "../Header/bloom_filter.h"


// -------------------- Bloom Filter --------------------
BloomFilter::BloomFilter(size_t num, double fRate) 
    : n(num), p(fRate) 
{
    // cal số bit m và số hàm băm k
    m = static_cast<size_t>(-(double)n * log(p) / (log(2) * log(2)));
    k = max(1, (int)round(((double)m / n) * log(2)));

    bitArray.assign(m, false);
}

void BloomFilter::insert(const string &item) {
    for (int i = 0; i < k; i++) {
        size_t hashValue = hash<string>{}(item + to_string(i)) % m; //tăng tính phân tán = cách cộng 1 chuỗi ngẫu nhiên (i)
        bitArray[hashValue] = true;
    }
}

bool BloomFilter::contains(const string &item) const {
    for (int i = 0; i < k; i++) {
        size_t hashValue = hash<string>{}(item + to_string(i)) % m;
        if (!bitArray[hashValue]) return false;
    }
    return true;
}

// -------------------- pHash --------------------
string pHash(const string &imagePath) {
    cv::Mat img = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Error: Cannot read image " << imagePath << endl;
        return "";
    }

    cv::Mat resized;
    cv::resize(img, resized, cv::Size(32, 32));

    cv::Mat floatMat;
    resized.convertTo(floatMat, CV_32F);

    cv::Mat dctMat;
    cv::dct(floatMat, dctMat);

    cv::Mat dctLow = dctMat(cv::Rect(0, 0, 8, 8)); // get top-left 8x8 matrix;

    double meanVal = cv::mean(dctLow)[0]; //cal the mean val;=

    string hashStr;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            hashStr.push_back(dctLow.at<float>(i, j) > meanVal ? '1' : '0');
        }
    }

    return hashStr;
}

// -------------------- Hamming Distance --------------------
int hammingDistance(const string &hash1, const string &hash2) {
    if (hash1.size() != hash2.size()) return -1;

    int dist = 0;
    for (int i = 0; i < hash1.size(); i++) {
        if (hash1[i] != hash2[i]) dist++;
    }
    return dist;
}
