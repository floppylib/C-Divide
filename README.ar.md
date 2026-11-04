<div align="center">
  <img src="assets/logo-padded.svg" alt="شعار C÷ الرسمي" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><strong>التنزيلات:</strong> <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip">الشيفرة المصدرية ZIP</a> · <a href="https://cmake.org/download/">CMake 3.20+</a> · <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/">أدوات C++ لويندوز</a> · <a href="https://www.msys2.org/">MSYS2 / GCC</a> · <a href="https://releases.llvm.org/">LLVM / Clang</a></p>
  <p><em>يتطلب البناء CMake 3.20 أو أحدث ومترجم C++20. لا تتوفر ملفات تنفيذية جاهزة لـ C÷ حتى الآن.</em></p>
  <p><strong>سهل التعلّم، قويّ في البناء.</strong></p>
  <p>لغة برمجة واضحة تهدف إلى الترجمة إلى ملفات تنفيذية أصلية.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## ما هي C÷؟

‏C÷، وتُنطق **C-Divide**، مشروع مفتوح المصدر لتطوير لغة برمجة. يهدف المشروع إلى جعل البرمجة أسهل للمبتدئين مع الحفاظ على البنية اللازمة لبناء برامج احترافية.

الرؤية طويلة المدى هي إنشاء **لغة تُترجم إلى شيفرة تنفيذية أصلية**، مع خيارات لإدارة الذاكرة تلقائياً أو بشكل صريح، ومكتبة قياسية وأدوات تطوير متكاملة.

> **الحالة الفعلية:** يحتوي المستودع حالياً على أساس أولي للمحلّل المعجمي والمحلّل النحوي وفحص البنية. لا يمكنه تشغيل برامج C÷ أو إنشاء ملفات تنفيذية أصلية بعد. يجري تطوير المشروع للوصول إلى إصدار 1.0 مكتمل.

## مثال على صياغة اللغة

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

يوضح المثال أسلوب اللغة المستهدف. يستطيع الجزء الحالي تحليل الرموز وفحص الصياغة للتراكيب المدعومة؛ أما تشغيل البرامج والتحليل الدلالي وفحص الأنواع فما زالت قيد التطوير. **الكلمات المحجوزة في لغة C÷ نفسها باللغة الإنجليزية حالياً**؛ ترجمة ملفات README لا تعني أن الكلمات المحجوزة المترجمة مدعومة.

## البدء السريع

لا تحتاج إلى حساب GitHub أو تثبيت Git لتنزيل الشيفرة المصدرية.

**[تنزيل الشيفرة المصدرية بصيغة ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

متطلبات البناء: مترجم C++20 ونسخة CMake 3.20 أو أحدث.

**لينكس**

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

**ويندوز — PowerShell**

~~~powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
~~~

جرّب أدوات التطوير الحالية:

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

يعرض الأمر <code>lex</code> الرموز ومواقعها في المصدر. ويفحص <code>check</code> البنية المعجمية والنحوية. لا تشغّل هذه الأوامر البرامج ولا تنتج ملفات تنفيذية أصلية حتى الآن.

## حالة التطوير

| المكوّن | الحالة |
| --- | --- |
| مشروع C++20 وCMake | ✅ |
| المحلّل المعجمي وتشخيص المواقع | ✅ إصدار أولي |
| المحلّل النحوي وفحص الصياغة | ✅ إصدار أولي |
| قواعد المتغيرات والدوال والشروط والحلقات | ✅ يتم تحليلها ولا تُنفّذ |
| توليد الشيفرة الأصلية | 🛠 مخطط له |
| بيئة التشغيل وتنفيذ البرامج | 🛠 مخطط له |
| التحليل الدلالي وفحص الأنواع | 🛠 مخطط له |
| المكتبة القياسية والوحدات ومدير الحزم | 🛠 مخطط لها |
| المنسّق ومصحح الأخطاء | 🛠 مخطط له |

راجع [خارطة الطريق](docs/roadmap.md) و[أدلة البدء](docs/getting-started.md).

## التنزيلات والمجتمع

- **الشيفرة المصدرية:** [أرشيف ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)، ولا يتطلب حساباً.
- **الإصدارات:** ستُنشر الحزم الجاهزة في صفحة [Releases](https://github.com/floppylib/C-Divide/releases) بعد إنشاء وسم إصدار ونجاح عملية البناء. لا توجد حزم جاهزة منشورة حالياً.
- **المساهمة:** اقرأ [CONTRIBUTING.md](CONTRIBUTING.md) و[سياسة الأمان](SECURITY.md).

## التوثيق والترخيص

الأدلة التقنية مكتوبة بالإنجليزية أساساً في الوقت الحالي، ونرحب بالمساهمات لترجمتها. الشيفرة المصدرية مرخصة بموجب [MIT](LICENSE)، والوثائق بموجب [CC BY 4.0](LICENSE-DOCS).

---

<div align="center"><sub>يُطوَّر بشفافية، صُمّم للتعلّم، وجاهز للنمو.</sub></div>
