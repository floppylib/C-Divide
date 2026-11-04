<div align="center">
  <img src="assets/logo-padded.svg" alt="لوگوی رسمی C÷" width="144">
  <h1>C÷ — سی‌دایواید</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="دانلود مستقیم سورس C÷ (ZIP)" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="دانلود CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="ابزار کامپایل C++ برای ویندوز" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 و GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>برای ساخت پروژه به CMake نسخهٔ 3.20 یا جدیدتر و یک کامپایلر C++20 نیاز دارید. فایل اجرایی آمادهٔ C÷ هنوز منتشر نشده است.</em></p>
  <p><strong>یادگیری ساده؛ قدرت برای ساختن پروژه‌های بزرگ.</strong></p>
  <p>یک زبان برنامه‌نویسی خوانا با هدف کامپایل مستقیم به فایل اجرایی بومی.</p>
  <p>
    <a href="https://github.com/floppylib/C-Divide/actions/workflows/ci.yml"><img alt="وضعیت ساخت و تست" src="https://img.shields.io/github/actions/workflow/status/floppylib/C-Divide/ci.yml?branch=main&label=build%20%26%20tests"></a>
    <a href="LICENSE"><img alt="مجوز MIT" src="https://img.shields.io/badge/code-MIT-2ea44f.svg"></a>
    <a href="LICENSE-DOCS"><img alt="مجوز مستندات" src="https://img.shields.io/badge/docs-CC%20BY%204.0-blue.svg"></a>
  </p>
  <p>
    <a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> ·
    <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> ·
    <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> ·
    <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a>
  </p>
  <p><a href="docs/roadmap.md">نقشهٔ راه</a> · <a href="docs/language.md">راهنمای زبان</a> · <a href="docs/architecture.md">معماری</a></p>
</div>

---

## ✨ C÷ چیست؟

C÷ یا **C-Divide** یک پروژهٔ متن‌باز برای ساخت زبان برنامه‌نویسی‌ای است که یادگیری آن برای تازه‌کارها ساده باشد، اما در آینده ساختار و ابزار لازم برای نرم‌افزارهای جدی را هم داشته باشد.

هدف بلندمدت، زبانی **کامپایل‌شونده به فایل اجرایی بومی** با امکان مدیریت خودکار و دستی حافظه، کتابخانهٔ استاندارد و ابزارهای مناسب توسعه است.

> **وضعیت فعلی پروژه:** C÷ علاوه بر Lexer، Parser و بررسی نحوی اولیه، یک backend آزمایشی برای کامپایل بومی دارد. دستورهای `cdiv build` و `cdiv run` بخش پشتیبانی‌شدهٔ زبان را به C++20 تبدیل می‌کنند و با کامپایلر C++ سیستم، فایل اجرایی واقعی می‌سازند. تحلیل معنایی کامل، بررسی نوع‌ها، ماژول‌ها، کتابخانهٔ استاندارد و مدل نهایی حافظه هنوز در دست توسعه‌اند؛ این نسخه هنوز C÷ 1.0 نهایی نیست.

## 🚀 نمونه‌ای از زبان

~~~cdiv
name = "Hello, C÷!";
print(name);

age = 20;
if age >= 18 {
    print("Welcome!");
} else {
    print("Keep learning!");
}

fn add(a: int, b: int) -> int {
    return a + b;
}
~~~

این کد سبک طراحی‌شدهٔ زبان را نشان می‌دهد. کامپایلر فعلی می‌تواند کد را توکن‌سازی و از نظر نحوی بررسی کند و بخش پشتیبانی‌شده را از طریق backend مبتنی بر C++20 به کد بومی تبدیل کند. تحلیل معنایی کامل، بررسی نوع‌ها و امکانات کامل Runtime و کتابخانه هنوز در دست توسعه‌اند. **کلیدواژه‌های خود زبان C÷ فعلاً انگلیسی هستند**؛ ترجمهٔ راهنماها به معنی پیاده‌سازی دستورهای فارسی یا زبان‌های دیگر نیست.

## 🧭 اصول طراحی

| اصل | مسیر پروژه |
| --- | --- |
| خوانایی | واژه‌های آشنا، بلوک‌های مرتب و دستورهای قابل پیش‌بینی |
| کارایی | هدف، تولید فایل اجرایی بومی است |
| حافظه | مدیریت خودکار و کنترل صریح، با قواعد ایمنی مشخص |
| سازگاری | ابتدا ویندوز و لینوکس؛ سپس پلتفرم‌های دیگر |
| ابزارها | رابط خط فرمان روشن، خطایابی خوب، قالب‌بند و ابزار بسته‌ها |
| دسترس‌پذیری | دانلود سورس و نصب ساده، بدون نیاز به یادگیری Git |

## ⚡ شروع سریع

### ۱. دریافت سورس، بدون Git

برای دانلود پروژه نیازی به حساب GitHub، نصب Git یا کار با ترمینال ندارید.

**[⬇ دانلود مستقیم سورس به‌صورت ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

فایل را از حالت فشرده خارج کنید و پوشه را در ترمینال باز کنید. در صورت تمایل می‌توانید از Git استفاده کنید:

~~~sh
git clone https://github.com/floppylib/C-Divide.git
cd C-Divide
~~~

### ۲. ساخت پروژه

پیش‌نیازها: کامپایلر C++20 و نسخهٔ CMake 3.20 یا جدیدتر.

**لینوکس**

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

**ویندوز — PowerShell**

~~~powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
~~~

### ۳. امتحان ابزارهای توسعه

نام فایل اجرایی <code>cdiv</code> است (در ویندوز <code>cdiv.exe</code>).

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
cdiv run examples/hello.cdiv
cdiv build examples/hello.cdiv
~~~

- دستور <code>lex</code> توکن‌ها و موقعیت آن‌ها در کد را نمایش می‌دهد.
- دستور <code>check</code> ساختار واژگانی و دستوری را بررسی می‌کند.

دستور `run` سورس را به یک فایل اجرایی موقت تبدیل و اجرا می‌کند. دستور `build` فایل اجرایی بومی را داخل پوشهٔ `build/` می‌سازد (یا با گزینهٔ `-o` در مسیر دلخواه ذخیره می‌کند). هر دو دستور به یک کامپایلر C++20 سالم نیاز دارند؛ برای انتخاب آن می‌توان متغیر محیطی `CXX` را تنظیم کرد.

## 📦 دریافت‌ها

- **کد منبع:** از لینک ZIP بالا استفاده کنید؛ حساب کاربری لازم نیست.
- **ابزارهای کامپایلر آماده:** پس از ایجاد یک برچسب نسخه و موفقیت فرایند انتشار، بسته‌ها در [صفحهٔ Releases](https://github.com/floppylib/C-Divide/releases) قرار می‌گیرند.
- **اسکریپت‌های نصب:** فایل‌های <code>scripts/install.sh</code> و <code>scripts/install.ps1</code> برای نصب فایل اجرایی ساخته‌شده در حساب کاربر در نظر گرفته شده‌اند.

**هنوز بستهٔ آماده‌ای منتشر نشده است.** گردش‌کار انتشار آماده شده، اما فایل دانلودی تنها پس از ساخت موفق یک نسخهٔ برچسب‌گذاری‌شده منتشر خواهد شد.

## 🧩 چه بخش‌هایی پیاده‌سازی شده‌اند؟

| بخش | وضعیت |
| --- | --- |
| پروژهٔ C++20 و CMake | ✅ |
| Lexer و گزارش موقعیت خطا | ✅ نسخهٔ اولیه |
| Parser و بررسی دستورها | ✅ نسخهٔ اولیه |
| متغیرها، فراخوانی‌ها، تابع‌ها، شرط‌ها و حلقه‌ها | ✅ تجزیه می‌شوند؛ بخش پشتیبانی‌شده کامپایل می‌شود |
| backend اولیهٔ تولید کد بومی C++20 | ✅ نسخهٔ آزمایشی |
| دستورهای `cdiv build` و `cdiv run` | ✅ نسخهٔ آزمایشی |
| گردش‌کار خودکار ساخت و تست | ✅ پیکربندی شده |
| تحلیل معنایی و بررسی ایستای نوع‌ها | 🛠 برنامه‌ریزی‌شده |
| Runtime کامل و کتابخانهٔ استاندارد | 🛠 برنامه‌ریزی‌شده |
| تحلیل معنایی و نوع‌ها | 🛠 برنامه‌ریزی‌شده |
| کتابخانهٔ استاندارد و سیستم ماژول | 🛠 برنامه‌ریزی‌شده |
| مدل مدیریت حافظه | 🧭 در مرحلهٔ طراحی |
| مدیر بسته، قالب‌بند و دیباگر | 🛠 برنامه‌ریزی‌شده |

برای دیدن مراحل آینده، [نقشهٔ راه](docs/roadmap.md) را ببینید.

## 📚 مستندات

| راهنما | محتوا |
| --- | --- |
| [شروع به کار](docs/getting-started.md) | ساخت C÷ در ویندوز و لینوکس |
| [راهنمای زبان](docs/language.md) | دستورهایی که Front End فعلی می‌شناسد |
| [معماری](docs/architecture.md) | ساختار و بخش‌های کامپایلر |
| [Backend بومی](docs/native-backend.md) | روند ساخت فایل اجرایی و محدودیت‌های فعلی |
| [تاریخچه تغییرات](CHANGELOG.md) | نسخه‌ها و تغییرات پیاده‌سازی |
| [نقشهٔ راه](docs/roadmap.md) | مراحل برنامه‌ریزی‌شده |
| [پرسش‌های متداول](docs/faq.md) | پاسخ پرسش‌های رایج |
| [دانلودها](docs/downloads.md) | سورس و بسته‌های انتشار |

توضیح backend بومی و محدودیت‌های فعلی آن در [مستندات Native Backend](docs/native-backend.md) آمده است. راهنماهای فنی فعلاً ابتدا به انگلیسی نوشته می‌شوند. برای کمک به ترجمه و هماهنگ نگه‌داشتن زبان‌ها، [راهنمای مشارکت در ترجمه](TRANSLATIONS.md) را ببینید.

## 🤝 مشارکت

پیشنهاد، گزارش باگ، بهتر کردن مستندات و مشارکت در کد همگی ارزشمندند.

- پیش از ارسال Pull Request، فایل [CONTRIBUTING.md](CONTRIBUTING.md) را بخوانید.
- برای گزارش باگ و پیشنهاد قابلیت از قالب Issue استفاده کنید.
- [قوانین رفتار جامعه](CODE_OF_CONDUCT.md) و [سیاست امنیتی](SECURITY.md) را مطالعه کنید.

حتی یک گزارش دقیق از باگ یا مثال بهتر هم کمک بزرگی است.

## 📜 مجوزها

- **کد منبع:** [MIT](LICENSE)
- **مستندات:** [Creative Commons Attribution 4.0](LICENSE-DOCS)

در صورت اضافه شدن وابستگی‌های شخص ثالث، اطلاعات آن‌ها در [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) ثبت می‌شود.

---

<div align="center"><sub>متن‌باز ساخته می‌شود؛ برای یادگیری طراحی شده و برای رشد آماده است.</sub></div>
