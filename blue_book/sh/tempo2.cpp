#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Sample
{
    int label, pred;
    double score;
};

void fuseMatrix(vector<Sample> &samples, double &tpr, double &fpr)
{
    int tp = 0, fp = 0, tn = 0, fn = 0;
    for (int i = 0; i < samples.size(); i++) {
        if (samples[i].label == samples[i].pred) {
            if (samples[i].pred == 1) {
                tp++;
            } else {
                tn++;
            }
        } else {
            if (samples[i].pred == 1) {
                fp++;
            } else {
                fn++;
            }
        }
    }
    tpr = tp / (double)(tp + fn);
    fpr = fp / (double)(tn + fp);
    cout << tp << " " << fp << " " << tn << " " << fn << endl;
}

bool compare(Sample A, Sample B)
{
    return A.score < B.score;
}

int main()
{
    // cout<<"hello world\n";
    // 读取数据
    int num_sample = 0;
    cin >> num_sample;
    vector<Sample> samples(num_sample);
    char c;
    for (int i = 0; i < num_sample; i++) {
        cin >> c >> samples[i].score;
        if (c == '+') {
            samples[i].label = 1;
        } else {
            samples[i].label = 0;
        }
    }
    sort(samples.begin(), samples.end(), compare);

    // for(int i=0; i<samples.size(); i++){
    //     cout<<samples[i].label<<" "<<samples[i].score<<endl;
    // }
    // cout<<endl;

    // 截断点依次取score值
    vector<double> fprs(num_sample);
    vector<double> tprs(num_sample);
    for (int i = 0; i < num_sample; i++) {
        //做预测
        for (int j = 0; j < num_sample; j++) {
            if (samples[j].score < samples[i].score) {
                samples[j].pred = 0;
            } else {
                samples[j].pred = 1;
            }
        }
        //计算fpr, tpr
        cout << samples[i].score << endl;
        fuseMatrix(samples, tprs[i], fprs[i]);
    }
    // 计算面积
    // for(int i=0; i<num_sample; i++){
    //     cout<<fprs[i]<<" "<<tprs[i]<<endl;
    // }
    // cout<<endl;

    double auc = 0;
    for (int i = 0; i < num_sample - 1; i++) {
        auc += (fprs[i] - fprs[i + 1]) * tprs[i + 1];
    }
    cout << auc << endl;

    return 0;
}