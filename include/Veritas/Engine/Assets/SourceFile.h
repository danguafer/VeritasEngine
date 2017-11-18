#pragma once

#include <string>

namespace Veritas {
    namespace Engine {
        namespace Assets {
            class SourceFile {
                public:
                    SourceFile(const std::string& path);
                    SourceFile(SourceFile&& move);

                    void operator=(SourceFile&& move);

                    const std::string& getSource() const;
                private:
                    std::string source;
            };
        };
    }
}
