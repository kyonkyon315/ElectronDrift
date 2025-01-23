#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

#include "Force.h"

#include "Electron.h"


int main()
{
    
    EarthMagneticField magneticField;

    //シミュレーションの時間間隔
    Time dt = 0.001;

    double q = 1.602176634e-19;
    
    //地球磁気圏の高度
    double R = 6e7;

    //荷電粒子の初期速度
    double v = 3e5;

    //初期ピッチ各
    double alpha = 0.4;
    

    //荷電粒子質量
    double me = 1.67e-27;
    Electron electron(Coordinate(R, 0., 0.), Velocity(v*cos(alpha*3.1415), 0., v *sin(alpha*3.1415)), Weight(me));


    //荷電粒子の位置と速度から力を計算する関数
    auto func = [&](const Coordinate& arg1, const Velocity& arg2) {
        magneticField.setPlace(arg1);
        magneticField.calc();
        return arg2 * magneticField * q;//速度*磁場*電荷
        };

    
    //+=dtの回数
    size_t N = 1000000;

    double time(0.);
    std::string alpha_str = std::to_string(alpha);
    while (alpha_str[alpha_str.size() - 1] == '0') {
        alpha_str.pop_back();
    }
    std::ofstream ofs("data_alpha="+alpha_str+ ".txt");
    
    for (size_t i = 0; i < N; i++) {
        ofs << electron << '\n';
        
        //次の時刻の位置と速度を計算する関数（ルンゲクッタ法）
        electron.upDate(func, dt);
        time += dt.get_val();
        if (i % 100 == 0)std::cout << i<<'\n';
    }
    
}
