#include "doublewidget.h"
#include "utility.h"

DoubleWidget::DoubleWidget(const cv::Mat &input, QWidget *parent)
    : ToolWidget(parent)
{
    return;
    cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::load("/home/bartoli/Dropbox/Progetti/Sherlock2/svm/first_digit.yml");

    const float MIN_DIST = -1.76819;
    const float MAX_DIST = +1.36294;

    cv::Mat features;
    firstDigitFeatures(input, features);
    cv::Mat results;
    float dist = svm->predict(features, results, cv::ml::StatModel::RAW_OUTPUT);
    //QMessageBox::information(this, QApplication::applicationName(), QString::number(dist));
    float probability;
    if (dist > 0)
    {
        if (dist > MAX_DIST)
            probability = -100;
        else
            probability = -dist / MAX_DIST * 100;
    }
    else
    {
        if (dist < MIN_DIST)
            probability = +100;
        else
            probability = dist / MIN_DIST * 100;
    }
}

void DoubleWidget::firstDigitFeatures(const cv::Mat input, cv::Mat &features)
{
    const int SKIP_DC    = 1;
    const int NUM_MODES  = 20;
    const int NUM_DIGITS = 10;
    const std::vector<int> DIGITS = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    const cv::Mat SCALING = (cv::Mat_<float>(NUM_MODES * DIGITS.size(), 2) <<
        0.023303, 0.513002,    0.005404, 0.306991,    0.004053, 0.465721,
        0.003377, 0.346842,    0.000675, 0.119216,    0.000675, 0.364404,
        0.000338, 0.416751,    0.000000, 0.309017,    0.000000, 0.363728,
        0.031746, 0.538332,    0.008781, 0.313745,    0.004728, 0.170550,
        0.003715, 0.321851,    0.000000, 0.298210,    0.002364, 0.340763,
        0.001689, 0.448159,    0.000000, 0.348531,    0.000338, 0.183384,
        0.028369, 0.557582,    0.001351, 0.295846,    0.000000, 0.315096,
        0.000252, 0.340892,    0.000338, 0.133739,    0.000000, 0.337048,
        0.000338, 0.348450,    0.000000, 0.339075,    0.000000, 0.236744,
        0.009456, 0.520770,    0.000338, 0.331982,    0.000675, 0.166160,
        0.000338, 0.340426,    0.000000, 0.299223,    0.000000, 0.350895,
        0.000338, 0.437352,    0.000000, 0.368794,    0.000000, 0.076663,
        0.027693, 0.499831,    0.003040, 0.340763,    0.000000, 0.374536,
        0.000338, 0.338399,    0.000338, 0.336035,    0.000338, 0.491726,
        0.000000, 0.394461,    0.000000, 0.353597,    0.000675, 0.455589,
        0.026342, 0.537318,    0.000000, 0.291118,    0.000000, 0.363728,
        0.000000, 0.170550,    0.000000, 0.400878,    0.000000, 0.360014,
        0.000000, 0.088146,    0.000000, 0.349544,    0.000000, 0.284363,
        0.028369, 0.554205,    0.000675, 0.299223,    0.000000, 0.355623,
        0.000000, 0.344478,    0.000000, 0.106045,    0.000000, 0.343465,
        0.000000, 0.346505,    0.000000, 0.399865,    0.000000, 0.282675,
        0.018237, 0.532590,    0.004390, 0.302938,    0.000000, 0.340763,
        0.000000, 0.342452,    0.000000, 0.389058,    0.000000, 0.271868,
        0.000000, 0.416751,    0.000000, 0.460655,    0.000000, 0.370483,
        0.040865, 0.605539,    0.000675, 0.295846,    0.000000, 0.344433,
        0.000000, 0.357987,    0.000000, 0.122256,    0.000000, 0.361027,
        0.000000, 0.373522,    0.000000, 0.379264,    0.000000, 0.251942,
        0.039176, 0.612631,    0.000000, 0.348193,    0.000000, 0.297872,
        0.000000, 0.357649,    0.000000, 0.345154,    0.000000, 0.102668,
        0.000000, 0.388720,    0.000000, 0.313745,    0.000000, 0.404255,
        0.021952, 0.561297,    0.000000, 0.334347,    0.000000, 0.355285,
        0.000000, 0.153664,    0.000000, 0.460993,    0.000000, 0.273556,
        0.000000, 0.380952,    0.000000, 0.088821,    0.000000, 0.387707,
        0.020601, 0.559608,    0.000000, 0.292131,    0.000000, 0.356636,
        0.000000, 0.181695,    0.000000, 0.475177,    0.000000, 0.359338,
        0.000000, 0.093549,    0.000000, 0.373185,    0.000000, 0.291456,
        0.016548, 0.535630,    0.000000, 0.322188,    0.000338, 0.289092,
        0.000000, 0.366093,    0.000000, 0.147923,    0.000000, 0.479905,
        0.000000, 0.109085,    0.000000, 0.377913,    0.000000, 0.073286,
        0.006417, 0.544748,    0.000000, 0.541709,    0.000000, 0.231341,
        0.000000, 0.246538,    0.000000, 0.350718,    0.000000, 0.137116,
        0.000000, 0.449510,    0.000000, 0.095576,    0.000000, 0.083418,
        0.019926, 0.590341,    0.000000, 0.467072,    0.000000, 0.441405,
        0.000000, 0.405268,    0.000000, 0.162445,    0.000000, 0.127660,
        0.000000, 0.216481,    0.000000, 0.376224,    0.000000, 0.068558,
        0.009119, 0.563323,    0.000000, 0.558595,    0.000000, 0.315772,
        0.000000, 0.237082,    0.000000, 0.366591,    0.000000, 0.121243,
        0.000000, 0.090510,    0.000000, 0.476528,    0.000000, 0.069909,
        0.008443, 0.576494,    0.000000, 0.562648,    0.000000, 0.231003,
        0.000000, 0.262749,    0.000000, 0.365755,    0.000000, 0.110773,
        0.000000, 0.466059,    0.000000, 0.061128,    0.000000, 0.104357,
        0.008781, 0.547112,    0.000000, 0.545424,    0.000000, 0.208713,
        0.000000, 0.377575,    0.000000, 0.165485,    0.000000, 0.111787,
        0.000000, 0.474164,    0.000000, 0.318811,    0.000000, 0.365755,
        0.006417, 0.548126,    0.000000, 0.565012,    0.000000, 0.193178,
        0.000000, 0.373522,    0.000000, 0.103006,    0.000000, 0.088821,
        0.000000, 0.471125,    0.000000, 0.308342,    0.000000, 0.373522,
        0.021952, 0.555893,    0.000000, 0.582236,    0.000000, 0.230665,
        0.000000, 0.210402,    0.000000, 0.369363,    0.000000, 0.119554,
        0.000000, 0.453901,    0.000000, 0.052009,    0.000000, 0.113813);

    cv::Mat gray = Utility::padImage(input, Utility::DCT_SIZE);
    cvtColor(gray, gray, CV_BGR2GRAY);
    gray.convertTo(gray, CV_32F);
    cv::Mat digits_pdf(NUM_MODES, NUM_DIGITS, CV_32F);
    digits_pdf.setTo(0);
    for (int i = 0; i < input.rows - Utility::DCT_SIZE; i += Utility::DCT_SIZE)
    {
        for (int j = 0; j < input.cols - Utility::DCT_SIZE; j += Utility::DCT_SIZE)
        {
            cv::Mat block(gray, cv::Rect(j, i, Utility::DCT_SIZE, Utility::DCT_SIZE));
            block -= 128;
            cv::Mat coeffs(Utility::DCT_SIZE, Utility::DCT_SIZE, CV_32F);
            cv::dct(block, coeffs);
            coeffs.convertTo(coeffs, CV_16S);
            for (int m = 0; m < NUM_MODES; ++m)
            {
                int i0 = Utility::ZIG_ZAG.at<int>(m + SKIP_DC, 0);
                int j0 = Utility::ZIG_ZAG.at<int>(m + SKIP_DC, 1);
                short coeff = coeffs.at<short>(i0, j0);
                int d = getFirstDigit(coeff);
                ++digits_pdf.at<float>(m, d);
            }
        }
    }

    features.create(1, NUM_MODES * DIGITS.size(), CV_32F);
    int f = 0;
    for (int m = 0; m < NUM_MODES; ++m)
    {
        float digits_sum = 0;
        for (int d = 0; d < NUM_DIGITS; ++d)
            digits_sum += digits_pdf.at<float>(m, d);
        for (int d = 0; d < NUM_DIGITS; ++d)
        {
            if (std::find(DIGITS.begin(), DIGITS.end(), d) != DIGITS.end())
            {
                float pdf = digits_pdf.at<float>(m, d) / digits_sum;
                float min_val = SCALING.at<float>(f, 0);
                float max_val = SCALING.at<float>(f, 1);
                features.at<float>(0, f) = 2 * (pdf - min_val) / (max_val - min_val) - 1;
                ++f;
            }
        }
    }
}

int DoubleWidget::getFirstDigit(int number)
{
    char buffer[12];
    sprintf(buffer, "%d", abs(number));
    return (buffer[0] - '0');
}
