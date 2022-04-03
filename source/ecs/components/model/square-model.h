
#ifndef LDGAME_ECS_SQUAREMODEL_H_
#define LDGAME_ECS_SQUAREMODEL_H_

#include <component.h>
#include <components/shader/shader.h>
#include <components/shader/shaders-data.h>

// TODO(Bassel): move some functionality to Model:Component
class SquareModel : public Component
{
public:
    SquareModel()
    {
        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
            1.0f, 1.0f, 0.0f,   // top right
            1.0f, -1.0f, 0.0f,  // bottom right
            -1.0f, -1.0f, 0.0f, // bottom left
            -1.0f, 1.0f, 0.0f   // top left
        };
        unsigned int indices[] = {
            0, 1, 3, // first Triangle
            1, 2, 3  // second Triangle
        };
        glGenVertexArrays(1, &VAO_);
        glGenBuffers(1, &VBO_);
        glGenBuffers(1, &EBO_);

        glBindVertexArray(VAO_);

        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

        shaderProgram_ = new Shader(vertex_shader, fragment_shader);
    }

    ~SquareModel()
    {
        glDeleteVertexArrays(1, &VAO_);
        glDeleteBuffers(1, &VBO_);
        glDeleteBuffers(1, &EBO_);

        delete shaderProgram_;
    }

    void Render()
    {
        shaderProgram_->use();

        glBindVertexArray(VAO_); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time
    }

    Shader *get_shader() const
    {
        return shaderProgram_;
    }

    glm::vec3 color_;

private:
    unsigned int VBO_, VAO_, EBO_;
    Shader *shaderProgram_;
};

#endif // LDGAME_ECS_SQUAREMODEL_H_